#ifndef SQUARE_H
#define SQUARE_H
#include "abstractshape.h"
#include <QPainter>
#
//assume qreal == double here
namespace pashazz
{
    class Square : public AbstractShape
    {
    public:
        Square() = delete; //запрет конструктора по умолчанию
        Square(const Point2D &m_centre, double edge, double tlRadius = 0, double trRadius = 0, double blRadius = 0, double brRadius = 0);
        void paint(QPainter *p) const;
        virtual bool isInside(const Point2D &point) const;
        virtual void move(const Point2D &delta)
        {
            setCentre(m_centre + delta);
        }

    //Свойства: set
        void setEdge(double);
        void setTopLeftRadius(double r);
        void setTopRightRadius(double r);
        void setBottomLeftRadius(double r);
        void setBottomRightRadius(double r);
    //get
        double topLeftRadius() const {return m_tlRadius;}
        double topRightRadius() const {return m_trRadius;}
        double bottomLeftRadius() const {return m_blRadius;}
        double bottomRightRadius() const {return m_brRadius;}
        double edge() const {return m_halfedge*2;}

        //др. функции
        Point2D topLeftCorner() const;
        Point2D topRightCorner() const;
        Point2D bottomLeftCorner() const;
        Point2D bottomRightCorner() const;


    protected:
        void transformCoords() {printf("%s has called \n", __func__);}


        //радиусы закруглений углов
        //C++11: non-static member initializer
        double m_tlRadius = 0; ///<радиус закругления левого верхнего угла
        double m_trRadius = 0; ///<радиус закругления правого верхнего угла
        double m_blRadius = 0; ///<радиус закругления левого нижнего угла
        double m_brRadius = 0; ///<радиус закругления левого нижнего угла
        //точки далее устанавливаются зависимо от Radius-переменных
        Point2D tlCurveCentre() const; ///<центр закругления левого нижнего угла
        Point2D trCurveCentre() const; ///<центр закругления правого нижнего угла
        Point2D blCurveCentre() const; ///<центр закругления левого нижнего угла
        Point2D brCurveCentre() const; ///<центр закругления правого нижнего угла

        Point2D tlCorner() const;
        Point2D trCorner() const;
        Point2D blCorner() const;
        Point2D brCorner() const;
        double m_halfedge;

    };
}

#endif // SQUARE_H
