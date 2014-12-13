#ifndef SQUARE_INL
#define SQUARE_INL
#include "square.h"

using namespace pashazz;
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

Point2D inline Square::topLeftCorner() const
{
    return (-m_centre).translate(tlCorner());
}

Point2D inline Square::topRightCorner() const
{
    return (-m_centre).translate(trCorner());
}

Point2D inline Square::bottomLeftCorner() const
{
    return (-m_centre).translate(blCorner());
}

Point2D inline Square::bottomRightCorner() const
{
    return (-m_centre).translate(brCorner());
}

#endif //SQUARE_INL
