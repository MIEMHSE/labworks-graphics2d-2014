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
        Square(const Point2D &m_centre, double edge);
        void paint(QPainter *p) const;
        virtual bool isInside(const Point2D &point) const;
        virtual void move(const Point2D &delta)
        {
            setCentre(m_centre + delta);
        }
        operator QRectF() const
        {
            return QRectF(topLeftCorner(), bottomRightCorner());
        }
    //Свойства: set
        void setEdge(double);
    //get
        double edge() const {return m_halfedge*2;}

        //др. функции
        Point2D topLeftCorner() const;
        Point2D topRightCorner() const;
        Point2D bottomLeftCorner() const;
        Point2D bottomRightCorner() const;


    protected:

        Point2D tlCorner() const;
        Point2D trCorner() const;
        Point2D blCorner() const;
        Point2D brCorner() const;
        double m_halfedge;
        void transformCoords() {std::cout << __func__ << " has just been called!\n";}

    };
}

#endif // SQUARE_H
