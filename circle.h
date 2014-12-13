/**
@file circle.cpp
@date 3 Dec 2014
@author Pavel Zinin

Класс, представляющий круг
*/
#ifndef CIRCLE_H
#define CIRCLE_H
#include "abstractshape.h"
#include "vector.h"
namespace pashazz
{
    class Circle : public AbstractShape
    {
    public:
        Circle() = delete;
        Circle(double x, double y, double radius);
        Circle (Point2D centre, double radius);

        virtual bool isInside(const Point2D &point) const;
        virtual void paint(QPainter *p) const;
        //properties
        void setRadius(double radius);
        double radius() const {return m_radius;}

        void move(const Point2D &delta)
         {
            setCentre(m_centre + delta);
         }


    private:
        double m_radius;


    };


}

#endif //CIRCLE_H
