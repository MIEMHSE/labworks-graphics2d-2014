#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H
/** @file abstractshape.h
 *
 * @brief Абстрактный класс представления геометрической фигуры и класс ошибки неположительного значения координаты
 * @author Pavel Zinin <pzinin@gmail.com>
 * @date 27 Nov 2014
 *
 */
#include <iostream>
#include "vector.h"
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

    /**
    * @class Vector2D
    *
    * двумерный вектор
    */

    class Vector2D;

    //Ошибка: неположительное число

    struct NonPositiveValueException
    {
        NonPositiveValueException() = delete;

        NonPositiveValueException(double val, const char * msg)
        {
            std::cerr << "runtime error: mon-positive value: " << val << " (" << msg << ")\n";
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

    //props
        virtual void setCentre(Point2D centre) {
        m_centre = centre;
        transformCoords();
    }


        virtual void setCentre(double x, double y)
        {
            setCentre(Point2D(x, y));
        }
        virtual Point2D centre() {return m_centre;}
   //painting:
        virtual void paint() = 0;

    protected:
        virtual void transformCoords() = 0;
        Point2D m_centre;
        //constructor
        AbstractShape(Point2D centre)
            :m_centre(centre) {}
    };
}
#endif // ABSTRACTSHAPE_H
