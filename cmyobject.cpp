#include "cmyobject.h"
using namespace pashazz;
bool CMy2DObjectA2::checkIntersection()
{ //можно было бы использовать более сложный алгоритм, но мне лень
    return ((m_radius3 > m_edge / 2) ||
            (m_radius1+m_radius2 > m_edge*m_edge+0.25*m_edge*m_edge));
}


CMy2DObjectA2::CMy2DObjectA2(Point2D centre, double edge, double radius1, double radius2, double radius3, double angle,  QBrush background, QBrush foreground)
:m_centre(centre), m_angle(angle)
{

    /* создать систему объектов; вариант 2A */
    QBrush brush (Qt::magenta, Qt::SolidPattern);
    sys = new GraphicsSystem(centre, angle,
            edge + 20, edge + 20,
            background, foreground);

    /* Квадрат в центре системы */
    square = new Square(Point2D(0,0), ui->boxSquare->value());
    sys->addObject(square, true, 0);

    /* Круг с центром в середине левой стороны квадрата */
    Point2D circle1_centre = square->topRightCorner() + Point2D(0, -square->edge()/2);

    circle1 = new Circle(circle1_centre, ui->boxRad1->value());
    sys->addObject(circle1, false, 0);


    /* Круг в левом верхнем углу квадрата */
    Point2D circle2_centre = square->topLeftCorner();
    circle2 = new Circle(circle2_centre, ui->boxRad2->value());
    sys->addObject(circle2, false, 0);

    /* маленький квадрат в левом нижнем углу */
    double circle3_radius = ui->boxRad3->value();
    Point2D minisquare_centre = square->bottomLeftCorner() + Point2D(circle3_radius/2, circle3_radius/2);

    /* создать сцену */
    scene = new pashazz::GraphicsScene(this);
    connect(scene, &GraphicsScene::mouseMoveSignal, this, &MainWindow::updateLabel);
    connect(scene, &GraphicsScene::mouseClickSignal, this, &MainWindow::showIfInside);

    scene->addItem(sys);
}
