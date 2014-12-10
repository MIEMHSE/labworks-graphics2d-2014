#include "graphicssystem.h"
#include <QGraphicsScene>
#include <QBrush>
#include "square.h"
#include "circle.h"
#include "scene.h"

namespace  pashazz
{

    class CMy2DObjectA2
    {

    public:
        CMy2DObjectA2(Point2D centre, double edge, double radius1, double radius2, double radius3, double angle, QBrush background = Qt::NoBrush, QBrush foreground = Qt::SolidPattern);
        ~CMy2DObjectA2();
        //Property begin
        //С.Аксенов настаивает на PascalCase нотации

        void SetCentre(const Point2D &centre) {m_centre = centre;}
        Point2D GetCentre() const {return m_centre;}

        void SetEdge(double);
        double edge() const {return m_edge;}

        void SetRadius1(double);
        double GetRadius1() const;

        void SetRadius2(double);
        double GetRadius2() const;

        void SetRadius3(double);
        double GetRadius3() const;

        void SetAngle(double angle) {m_angle  =  angle; /**< угол в радианах */}
        double GetAngle() const {return m_angle;}

        QGraphicsScene *scene;

    private:
        Point2D m_centre;
        pashazz::GraphicsSystem *sys;
        /* фигуры */
        pashazz::Square *square, *minisquare;
        pashazz::Circle *circle1, *circle2, *circle3;
        pashazz::GraphicsScene *scene;
        double m_edge, m_radius1, m_radius2, m_radius3, m_angle;
        QBrush m_background, m_foreground;

        /**
        * @brief проверяет границы фигуры
        *
        */
        bool checkIntersection();
    };


}