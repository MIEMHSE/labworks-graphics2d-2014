#include "square.h"


using namespace pashazz;

Square::Square(const Point2D &m_centre, double edge)
: AbstractShape(m_centre)
{
    setEdge(edge);

}


void inline Square::setEdge(double e)
{
    if (e < 0)
        throw NegativeValueException(e, "Pashazz::Square::m_halfedge");
    else
        m_halfedge = e/2;
}

Point2D inline Square::trCorner() const
{ //top right corner in center coords
    return Point2D(m_halfedge, m_halfedge);
}

Point2D inline Square::tlCorner() const
{
    return Point2D(-m_halfedge, m_halfedge);
}

Point2D inline Square::blCorner() const
{
    return Point2D(-m_halfedge, -m_halfedge);
}

Point2D inline Square::brCorner() const
{
    return Point2D(m_halfedge, -m_halfedge);
}



void Square::paint(QPainter *p) const
{
    p->drawRect(*this);
}

Point2D inline Square::topLeftCorner() const
{
    return (-m_centre).translate(tlCorner());
}

Point2D Square::topRightCorner() const
{
    return (-m_centre).translate(trCorner());
}

Point2D Square::bottomLeftCorner() const
{
    return (-m_centre).translate(blCorner());
}

Point2D Square::bottomRightCorner() const
{
    return (-m_centre).translate(brCorner());
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








