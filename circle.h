/**
@file circle.cpp
@date 3 Dec 2014
@author Pavel Zinin

Класс, представляющий круг
*/

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

    private:
        double m_radius;


    };


}