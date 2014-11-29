#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H
/** @file abstractshape.h
 *
 * @brief Абстрактный класс представления геометрической фигуры и класс точки
 * @author Pavel Zinin <pzinin@gmail.com>
 * @date 27 Nov 2014
 * @see abstractshape.cpp
 */

namespace pashazz
{
    /**
     * @class AbstractShape
     * @brief Абстрактная геометрическая фигура
     *
     * Это абстрактный класс, представляющий геометрическую фигуру. Вы должны наследоваться от этого класса
     */
    class AbstractShape;
    /**
     * @class Point2D
     *
     * Точка на плоскости
     */
    class Point2D;

    class Point2D
    {
    public:
        Point2D(double x = 0, double y = 0)
            :x(x), y(y) {}
        double x;
        double y;
        Point2D operator+(const Point2D &rvalue)
        {
            return Point2D(x+rvalue.x, y+rvalue.y);
        }
        Point2D operator-(const Point2D &rvalue)
        {
            return Point2D(x-rvalue.x, y-rvalue.y);
        }
        Point2D& operator+=(const Point2D &rvalue)
        {
            x += rvalue.x;
            y += rvalue.y;
            return *this;
        }
        Point2D& operator-=(const Point2D &rvalue)
        {
            x -= rvalue.x;
            y -= rvalue.y;
            return *this;
        }
        bool operator==(const Point2D &rvalue)
        {
            return x == rvalue.x && y == rvalue.y;
        }
        bool operator!=(const Point2D &rvalue)
        {
            return !operator==(rvalue);
        }
    };

    class AbstractShape
    {
    public:

        virtual void move(double dX, double dY, double dAngle = 0)
        {
            move(Point2D(dX, dY), dAngle);
        }

        virtual void move(const Point2D &delta, double dAngle = 0) = 0;
        virtual void rotate(double dAngle) = 0;
        virtual bool isInside(const Point2D &point) = 0;
   //painting:
        virtual void paint() = 0;

    protected:
        Point2D m_centre;
        AbstractShape(Point2D centre)
            :m_centre(centre) {}
    };
}
#endif // ABSTRACTSHAPE_H
