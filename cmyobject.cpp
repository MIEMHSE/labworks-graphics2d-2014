#include "cmyobject.h"

using namespace pashazz;

CMy2DObjectA2::CMy2DObjectA2(Point2D centre, double edge, double radius1, double radius2, double radius3, double angle,  QBrush background, QBrush foreground)
{

    /* создать систему объектов; вариант 2A */
    sys = new GraphicsSystem(centre, angle,
            edge + 20, edge + 20,
            foreground, background);

    /* Квадрат в центре системы */
    square = new Square(Point2D(0, 0), edge);
    sys->addObject(square, true, 2);

    /* Круг с центром в середине левой стороны квадрата */
    Point2D circle1_centre = square->topRightCorner() + Point2D(0, -square->edge() / 2);
    circle1 = new Circle(circle1_centre, radius1);
    sys->addObject(circle1, false, 1);


    /* Круг в левом верхнем углу квадрата */
    Point2D circle2_centre = square->topLeftCorner();
    circle2 = new Circle(circle2_centre, radius2);
    sys->addObject(circle2, false, 1);

    /* маленький квадрат в левом нижнем углу */

    Point2D minisquare_centre = square->bottomLeftCorner() + Point2D(radius3 / 2, radius3 / 2);
    minisquare = new Square(minisquare_centre, radius3);
    sys->addObject(minisquare, false, 1);

    /* Круг в левом нижнем углу, образующий закругление */
   circle3 = new Circle(minisquare->topRightCorner(), radius3);
   sys->addObject(circle3, true, 0);
    throwIntersection(); //проверим на пересечения
    /* создать сцену */
    scene = new GraphicsScene();
    scene->addItem(sys);


}

CMy2DObjectA2::~CMy2DObjectA2()
{
    delete sys;
    delete scene;
}

bool CMy2DObjectA2::checkIntersection(std::string &message) const
{ //TEST VERSION
    // 1) Базовые проверки: проверяем, находятся ли внутри самого квадрата наши полукруги
    // операция умножения единожды: оптимизация длины кода и быстродействия
    double edge = square->edge();
    if (circle1->radius() > edge || circle2->radius() > edge || circle3->radius() > edge)
    {
        message = "Круг(и) больше квадрата";
        return true;
    }


    // Проверим, есть ли пересечение у кругов 1 и 2. Для этого замеряем расстояние между центрами кругов и сравним его с радиусами
    Point2D d12 = circle1->centre() - circle2->centre();
    if (d12.length() < circle1->radius() + circle2->radius())
    {
        message = "Круги 1 и 2 пересекаются";
        return true;
    }


    //Проверим, что радиус круга 2 больше расстояния между центрами кругов 2 и 3. Если это так - границы самопересекаются
    Point2D d23 = circle2->centre() - circle3->centre();
    if (d23.length() < circle2->radius())
    {
        message = "Круг 2 заходит за границы круга 3";
        return true;
    }
    //То же самое с кругом 1
    Point2D d13 = circle1->centre() - circle3->centre();
    if (d13.length() < circle1->radius())
    {
        message = "Круг 1 заходит за границы круга 2";
        return false;
    }
        return true;


}

void CMy2DObjectA2::SetRadius3(double d)
{
    minisquare->setCentre(square->bottomLeftCorner() + Point2D(d / 2, d / 2));
    circle3->setCentre(minisquare->topRightCorner());
    circle3->setRadius(d);
    throwIntersection();
}


void CMy2DObjectA2::SetEdge(double d)
{
    square->setEdge(d);
    throwIntersection();
}

double inline CMy2DObjectA2::GetEdge() const
{
    return square->edge();
}

void  CMy2DObjectA2::SetRadius1(double d)
{
    circle1->setRadius(d);
    throwIntersection();
}

double inline CMy2DObjectA2::GetRadius1() const
{
    return circle1->radius();
}

void CMy2DObjectA2::SetRadius2(double d)
{
    circle2->setRadius(d);
    throwIntersection();
}

double inline CMy2DObjectA2::GetRadius2() const
{
    return circle2->radius();
}



double CMy2DObjectA2::GetRadius3() const
{
    return circle3->radius();
}

void CMy2DObjectA2::throwIntersection() const
{
    #ifndef NO_INTERSECTION
        return;
    #else
    std::string message;
    if (!checkIntersection(message))
    {
        throw std::invalid_argument(message);
    }
    #endif //NO_INTERSECTION
}

void CMy2DObjectA2::SetAngle(double angle)
{
    sys->setAngle(angle);
}

double CMy2DObjectA2::GetAngle() const
{
    return sys->angle();
}

void CMy2DObjectA2::Rotate(double dAngle)
{
    sys->rotate(dAngle);
}
