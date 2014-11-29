#include "square.h"
using namespace pashazz;

Square::Square(const Point2D &m_centre, double edge, double tlRadius, double trRadius, double blRadius, double brRadius)
:
{

}

/* privat s */
Point2D Square::trCurveCentre()
{
    return trCorner() + Point2D(-m_tlRadius, -m_tlRadius);
}

Point2D Square::blCurveCentre()
{
    return blCorner() + Point2D(m_tlRadius, m_tlRadius);
}

Point2D Square::brCurveCentre()
{
    return brCorner() + Point2D(-m_tlRadius, m_tlRadius);
}

Point2D inline Square::tlCurveCentre()
{
    return tlCorner() + Point2D(m_tlRadius, -m_tlRadius);
}

void inline Square::setTopLeftRadius(double r)
{
    if (r < m_halfedge && r > 0)
        m_tlRadius = r;
    else
        throw NonPositiveValueException(r, "Pashazz::Square::m_tlRadius");
}


void inline Square::setTopRightRadius(double r)
{
    if (r < m_halfedge && r >= 0)
        m_trRadius = r;
    else
        throw NonPositiveValueException(r, "Pashazz::Square::m_trRadius");
}


void inline Square::setBottomLeftRadius(double r)
{
    if (r < m_halfedge && r >= 0)
        m_blRadius = r;
    else
        throw NonPositiveValueException(r, "Pashazz::Square::m_blRadius");
}

void inline Square::setBottomRightRadius(double r)
{
    if (r < m_halfedge && r >= 0)
        m_brRadius = r;
    else
        throw NonPositiveValueException(r, "Pashazz::Square::m_brRadius");
}


Point2D inline Square::trCorner()
{ //top right corner in center coords
    return Point2D(m_halfedge, m_halfedge);
}

Point2D inline Square::tlCorner()
{
    return Point2D(-m_halfedge, m_halfedge);
}

Point2D inline Square::blCorner()
{
    return Point2D(-m_halfedge, -m_halfedge);
}

Point2D inline Square::brCorner()
{
    return Point2D(m_halfedge, -m_halfedge);
}

Point2D inline Square::topLeftCorner()
{
    return -m_centre.translate(tlCorner());
}

Point2D Square::topRightCorner()
{
    return -m_centre.translate(trCorner());
}

Point2D Square::bottomLeftCorner()
{
    return -m_centre.translate(blCorner());
}

Point2D Square::bottomRightCorner()
{
    return -m_centre.translate(brCorner());
}

