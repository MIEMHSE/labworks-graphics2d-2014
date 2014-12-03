#include "graphicssystem.h"

using namespace pashazz;
///GraphicsSystemObject methods begin
bool GraphicsSystemObject::isInside(const Point2D &p) const
{
     return m_pShape->isInside(p) == m_sign;
}
///GraphicsSystemObject methods end

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
     GraphicsSystemObject *obj = new GraphicsSystemObject(shape, sign);
     std::unique_ptr<GraphicsSystemObject> ptr(obj);
     if (m_system.size() <= zOrder)
          m_system.resize(zOrder + 1);
     m_system.at(zOrder).push_back(obj);
}

bool GraphicsSystem::isInside(const Point2D &point) const
{
     Point2D priv_point = m_centre.translate(point);
     priv_point.rotate(m_angle);

     for (auto layer : m_system) //прокручиваем все слои
          for (auto obj : layer)
               if (!obj->isInside(priv_point))
                    return false;

     return true;
}

