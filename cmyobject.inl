#ifndef CMYOBJECT_INL
#define CMYOBJECT_INL
#include "cmyobject.h"

using namespace pashazz;

void inline CMy2DObjectA2::SetRadius3(double r)
{
    //HARD CHECK
    if (r > square->edge()/2)
    {
        std::cout << "Warning: " << __func__ << " won't change radius of the curve, since the diameter would be more than the edge\n.";
        return;
    }
    minisquare->setCentre(square->bottomLeftCorner() + Point2D(r / 2, r / 2));
    minisquare->setEdge(r);
    circle3->setCentre(minisquare->topRightCorner());
    circle3->setRadius(r);
    throwIntersection();
}


double inline CMy2DObjectA2::GetEdge() const
{
    return square->edge();
}

void inline CMy2DObjectA2::SetRadius1(double d)
{
    circle1->setRadius(d);
    throwIntersection();
}

double inline CMy2DObjectA2::GetRadius1() const
{
    return circle1->radius();
}

void inline CMy2DObjectA2::SetRadius2(double d)
{
    circle2->setRadius(d);
    throwIntersection();
}

double inline CMy2DObjectA2::GetRadius2() const
{
    return circle2->radius();
}

double inline CMy2DObjectA2::GetRadius3() const
{
    return circle3->radius();
}


#endif //CMYOBJECT_INL
