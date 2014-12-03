#include "graphicssystem.h"

using namespace pashazz;
///GraphicsSystemObject methods begin
bool GraphicsSystemObject::isInside(const Point2D &p)
{
     return m_pShape.isInside(p) == m_sign;
}
///GraphicsSystemObject methods end

void GraphicsSystem::move(const Point2D &delta, double dAngle)
{
     m_centre += delta;
     m_angle += dAngle;
}

void GraphicsSystem::rotate(double dAngle)
{
     m_angle += dAngle;
}

void GraphicsSystem::addObject(AbstractShape *shape, bool sign = true, int zOrder = 0)
{
     GraphicsSystemObject *obj = new GraphicsSystemObject(shape, sign);
     std::unique_ptr<GraphicsSystemObject> ptr = obj;
     //if size <= zOrder...
     m_system[zOrder].push_back(obj);
}

void GraphicsSystem::isInside(const Point2D &point)
{
     Point2D priv_point = m_centre.translate(point);
     priv_point.rotate(m_angle);

     for (auto layer : m_system) //прокручиваем все слои
          for (auto obj : layer)
               if (!obj->isInside(priv_point))
                    return false;

     return true;
}
