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
        void setEdge(double);
    //get
        double topLeftRadius() const {return tlRadius;}
        double topRightRadius() const {return trRadius;}
        double bottomLeftRadius() const {return blRadius;}
        double bottomRightRadius() const {return brRadius;}
        double edge() const {return _edge;}
    private:

        //радиусы закруглений углов
        double tlRadius = 0; ///<радиус закругления левого верхнего угла
        double trRadius = 0; ///<радиус закругления правого верхнего угла
        double blRadius = 0; ///<радиус закругления левого нижнего угла
        double brRadius = 0; ///<радиус закругления левого нижнего угла
        //точки далее устанавливаются зависимо от Radius-переменных
        Point2D tlCurveCentre; ///<центр закругления левого нижнего угла
        Point2D trCurveCentre; ///<центр закругления правого нижнего угла
        Point2D blCurveCentre; ///<центр закругления левого нижнего угла
        Point2D brCurveCentre; ///<центр закругления правого нижнего угла

        double _edge;
        Point2D topLeftCorner;
        Point2D topRightCorner;
        Point2D bottomRightCorner;
        Point2D bottomLeftCorner;
    };
}

#endif // SQUARE_H
