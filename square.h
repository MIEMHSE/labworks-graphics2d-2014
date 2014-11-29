#ifndef SQUARE_H
#define SQUARE_H
#include "abstractshape.h"
#include <QPainter>
//assume qreal == double here
namespace pashazz
{
    class Square : public AbstractShape
    {
    public:
        Square() = delete; //запрет конструктора по умолчанию
        Square(const Point2D &m_centre, double edge, double tlRadius = 0, double trRadius = 0, double blRadius = 0, double brRadius = 0);
        void paint();
        bool isInside(const Point2D &point);

    //Свойства: set
        void setEdge(double);
        void setTopLeftRadius(double);
        void setTopRightRadius(double);
        void setBottomLeftRadius(double);
        void setBottomRightRadius(double);
    //get
        double topLeftRadius() const {return m_tlRadius;}
        double topRightRadius() const {return m_trRadius;}
        double bottomLeftRadius() const {return m_blRadius;}
        double bottomRightRadius() const {return m_brRadius;}
        double edge() const {return m_halfedge*2;}

        //др. функции
        Point2D topLeftCorner();
        Point2D topRightCorner();
        Point2D bottomLeftCorner();
        Point2D bottomRightCorner();
    protected:
        void transformCoords()
        {
            qDebug() << "transformCoords() called";
        }

        //радиусы закруглений углов
        //C++11: non-static member initializer
        double m_tlRadius = 0; ///<радиус закругления левого верхнего угла
        double m_trRadius = 0; ///<радиус закругления правого верхнего угла
        double m_blRadius = 0; ///<радиус закругления левого нижнего угла
        double m_brRadius = 0; ///<радиус закругления левого нижнего угла
        //точки далее устанавливаются зависимо от Radius-переменных
        Point2D tlCurveCentre(); ///<центр закругления левого нижнего угла
        Point2D trCurveCentre(); ///<центр закругления правого нижнего угла
        Point2D blCurveCentre(); ///<центр закругления левого нижнего угла
        Point2D brCurveCentre(); ///<центр закругления правого нижнего угла

        Point2D tlCorner();
        Point2D trCorner();
        Point2D blCorner();
        Point2D brCorner();
        double m_halfedge;
    };
}

#endif // SQUARE_H
