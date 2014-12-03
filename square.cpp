#include "square.h"


using namespace pashazz;

Square::Square(const Point2D &m_centre, double edge, double tlRadius, double trRadius, double blRadius, double brRadius)
: AbstractShape(m_centre)
{
    setEdge(edge);
    setTopLeftRadius(tlRadius);
    setTopRightRadius(trRadius);
    setBottomLeftRadius(blRadius);
    setBottomRightRadius(brRadius);
}


void inline Square::setEdge(double e)
{
    if (e <= 0)
        throw NonPositiveValueException(e, "Pashazz::Square::m_halfedge");
    else
        m_halfedge = e/2;
}
Point2D Square::trCurveCentre() const
{
    return trCorner() + Point2D(-m_tlRadius, -m_tlRadius);
}

Point2D Square::blCurveCentre() const
{
    return blCorner() + Point2D(m_tlRadius, m_tlRadius);
}

Point2D Square::brCurveCentre() const
{
    return brCorner() + Point2D(-m_tlRadius, m_tlRadius);
}

Point2D inline Square::tlCurveCentre() const
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
    return -m_centre.translate(tlCorner());
}

Point2D Square::topRightCorner() const
{
    return -m_centre.translate(trCorner());
}

Point2D Square::bottomLeftCorner() const
{
    return -m_centre.translate(blCorner());
}

Point2D Square::bottomRightCorner() const
{
    return -m_centre.translate(brCorner());
}


void Square::paint(QPainter *p) const
{
   /* QTransform trans; //трансформация системы координат QPainter в нашу
    trans.scale(1, -1); //у указывает вверх
    trans.translate(m_centre.x, m_centre.y); //центр в m_centre

*/

    }


bool Square::isInside(const Point2D &point) const
{ //Check whether the point is inside this square
    Point2D priv_point = m_centre.translate(point);
    if(fabs(priv_point.x) > m_halfedge || fabs(priv_point.y) > m_halfedge)
        return false; //Обычный случай - точка вне квадрата
    else
    {
        Point2D relPoint = trCurveCentre().translate(priv_point); //правое верхнее закругление
        double angle = relPoint.angle();
        if (relPoint.length() > m_trRadius && angle > 0 && angle < M_PI/4)
            return false; //Точка в квадрате, но за пределами правого верхнего закругления

        relPoint = tlCurveCentre().translate(priv_point);
        angle = relPoint.angle();

        if (relPoint.length() < m_tlRadius && angle > M_PI/4 && angle < M_PI/2)
            return false; //Точка в квадрате, но за пределами левого верхнего закругления

        relPoint = blCurveCentre().translate(priv_point);
        if (relPoint.length() < m_trRadius && angle > -M_PI/2 && angle < -M_PI/4)
            return false; //Точка в квадрате, но за пределами левого нижнего закругление

        relPoint = brCurveCentre().translate(priv_point);
        if (relPoint.length() < m_brRadius && angle > -M_PI/4 && angle < 0)
            return false; ///правого нижнего


    }
    return true;


}






