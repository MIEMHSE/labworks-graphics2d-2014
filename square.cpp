#include "square.h"
using namespace pashazz;
void inline Square::setEdge(double e)
{
    //устанавливает длину квадрата; устанавливает точки углов соответственно; точки закруглений соответственно
    _edge = e;

    //углы

}

void inline Square::setTopLeftRadius(double r)
{
   #warning TODO radius check range
    if (tlRadius != r)
        tlRadius = r;
    tlCurveCentre = topLeftCorner + Point2D(r, -r);
}


void inline Square::setTopRightRadius(double r)
{
    if (trRadius != r)
        trRadius = r;
    trCurveCentre = topRightCorner + Point2D(-r, -r);
}

void inline Square::setBottomLeftRadius(double r)
{
    if (blRadius != r)
        blRadius = r;
    blCurveCentre = bottomLeftCorner + Point2D(r, r);
}

void inline Square::setBottomRightRadius(double r)
{
    if (brRadius != r)
    brRadius = r;
    brCurveCentre = bottomRightCorner + Point2D(-r, r);
}


