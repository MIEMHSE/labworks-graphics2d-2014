#include "graphicssystem.h"
#include <QWidget>
#include <boost/range/adaptor/reversed.hpp>

using namespace pashazz;

GraphicsSystem::GraphicsSystem(const Point2D &centre, double angle, double height, double width, QBrush trueBrush, QBrush falseBrush)
    :m_centre(centre), m_angle(angle), m_height(height), m_width(width), m_trueBrush(trueBrush), m_falseBrush(falseBrush) {}
GraphicsSystem::~GraphicsSystem()
{
     for (const auto &layer : m_system)
          for (const auto &pair : layer)
               delete pair.first;

}

void inline GraphicsSystem::move(const Point2D &delta, double dAngle)
{
     m_centre += delta;
     m_angle += dAngle;
}

void  GraphicsSystem::rotate(double dAngle)
{
     m_angle += dAngle;
}

void GraphicsSystem::addObject(AbstractShape *shape, bool sign, unsigned int zOrder)
{
     //null checking
     if (!shape)
          throw std::invalid_argument("shape must not be NULL");

     if (m_system.size() <= zOrder)
          m_system.resize(zOrder + 1);

     // создаем объект GraphicsSystemObject в динамической памяти, который управляется умным указателем unique_ptr
     m_system.at(zOrder).push_back(std::pair<AbstractShape*,bool>(shape, sign));
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
     {
          for (const auto &pair : layer)
          {
               if (!pair.first->isInside(priv_point))
                    continue; //нечего проверять
               return pair.second; //Если знак фигуры '+', тогда true, если '-', то false.
          }
     }
     return false;
}

void GraphicsSystem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     //применяем матрицу трансформации к рисователю
     QTransform trSys;
     trSys.translate(m_centre.x, m_centre.y);
     trSys.rotateRadians(m_angle);
     painter->setTransform(trSys, true);
//     painter->setRenderHint(QPainter::Antialiasing);
     for(const auto &layer : boost::adaptors::reverse(m_system))
          for (const auto &pair : layer)
          {
#ifndef NDEBUG
              std::cout << "Adding Object " << pair.first->centre() << "; "<< pair.second << std::endl;
#endif

              pair.second ? painter->setBrush(m_trueBrush) : painter->setBrush(m_falseBrush);
              painter->setPen(Qt::NoPen);
              pair.first->paint(painter);
          }

}
