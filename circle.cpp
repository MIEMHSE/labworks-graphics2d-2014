#include "circle.h"

using namespace pashazz;

Circle::Circle(Point2D centre, double radius)
: AbstractShape(centre)
{
    setRadius(radius);

}

Circle::Circle(double x, double y, double radius)
: AbstractShape(Point2D (x,y))
{
    setRadius(radius);
}
bool Circle::isInside(const Point2D &point) const
{

    Point2D priv_point = m_centre.translate(point);
#ifndef NDEBUG
    std::cout << __BASE_FILE__ << ":" << __LINE__ << " " << __PRETTY_FUNCTION__ << " Coords: " << priv_point
              << " Result: " << (priv_point.length() <= m_radius) << std::endl;
    std::cout << "Length from the centre: " << priv_point.length() << std::endl;
#endif
    return priv_point.length() <= m_radius;
}

void Circle::paint(QPainter *p) const
{
    QPointF qtpoint (m_centre.x, m_centre.y);
    p->drawEllipse(qtpoint, m_radius, m_radius);
}

void inline Circle::setRadius(double radius)
{
    if (radius < 0)
    {
        throw NegativeValueException(radius, "Pashazz::Circle::m_radius");
    }
#ifndef NDEBUG
    std::cout << __func__ << ": m_radius: " << m_radius << "; m_centre: " << m_centre << std::endl;
#endif
    m_radius = radius;
}

