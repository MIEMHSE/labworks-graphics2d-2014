#include "graphicssystem.h"
#include <QWidget>

using namespace pashazz;
///GraphicsSystemObject methods begin
bool GraphicsSystemObject::isInside(const Point2D &p) const
{
     return m_pShape->isInside(p) == m_sign;
}
///GraphicsSystemObject methods end


GraphicsSystem::GraphicsSystem(const Point2D &centre, double angle, double height, double width, QBrush trueBrush, QBrush falseBrush)
    :m_centre(centre), m_angle(angle), m_height(height), m_width(width), m_trueBrush(trueBrush), m_falseBrush(falseBrush) {}
GraphicsSystem::~GraphicsSystem() {} //nothing to do yet

void inline GraphicsSystem::move(const Point2D &delta, double dAngle)
{
     m_centre += delta;
     m_angle += dAngle;
}

void inline GraphicsSystem::rotate(double dAngle)
{
     m_angle += dAngle;
}

void GraphicsSystem::addObject(AbstractShape *shape, bool sign, int zOrder)
{

     if (m_system.size() <= zOrder)
          m_system.resize(zOrder + 1);

     // создаем объект GraphicsSystemObject в динамической памяти, который управляется умным указателем unique_ptr
     m_system.at(zOrder).push_back(std::unique_ptr<GraphicsSystemObject>(new GraphicsSystemObject(shape,sign)));
}

bool GraphicsSystem::isInside(const Point2D &point) const
{
     //преобразуем координаты во внутреннюю систему

     Point2D priv_point = m_centre.translate(point);
     priv_point =  priv_point.rotateAxis(m_angle);
#ifndef NDEBUG
    std::cout << __BASE_FILE__ << ":" << __LINE__ << " " << __PRETTY_FUNCTION__ << " Coords: " << priv_point << std::endl;
#endif
     for (const auto &layer : m_system) //прокручиваем все слои
          for (const auto &ptr : layer)
               if (!ptr->isInside(priv_point))
                    return false;

     return true;
}

void GraphicsSystem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     //применяем матрицу трансформации к рисователю
     QTransform trSys;
     trSys.translate(m_centre.x, m_centre.y);
     trSys.rotateRadians(m_angle);
     painter->setTransform(trSys, true);
     painter->setRenderHint(QPainter::Antialiasing);
     for(const auto &layer : m_system)
          for (const auto &ptr : layer)
          {
              ptr->sign() ? painter->setBrush(m_trueBrush) : painter->setBrush(m_falseBrush);

              painter->setPen(Qt::NoPen);
              ptr->paint(painter);
          }

}
