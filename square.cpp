#include "square.h"


using namespace pashazz;

Square::Square(const Point2D &m_centre, double edge)
: AbstractShape(m_centre)
{
    setEdge(edge);

}



void Square::paint(QPainter *p) const
{
    p->drawRect(*this);
}




bool Square::isInside(const Point2D &point) const
{ //Check whether the point is inside this square
    Point2D priv_point = m_centre.translate(point);
#ifndef NDEBUG
    std::cout << __BASE_FILE__ << ":" << __LINE__ << " " << __PRETTY_FUNCTION__ << " Coords: " << priv_point
              << " Result: " <<   (fabs(priv_point.x) < m_halfedge && fabs(priv_point.y) < m_halfedge) << std::endl;

#endif

    return fabs(priv_point.x) < m_halfedge && fabs(priv_point.y) < m_halfedge;
}








