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
#include <QPainter>
#include <QtWidgets>

namespace pashazz
{
    /**
     * @class AbstractShape
     * @brief Абстрактная геометрическая фигура
     *
     * Это абстрактный класс, представляющий геометрическую фигуру. Вы должны наследоваться от этого класса
     */
    class AbstractShape;
    //Ошибка: неположительное число

    struct NegativeValueException
    {
        NegativeValueException() = delete;

        NegativeValueException(double val, const char * msg)
        {
            std::cerr << "runtime error: mon-positive value: " << val << " (" << msg << ")\n";
        }
    };



    class AbstractShape
    {
    public:
        virtual ~AbstractShape() {}
        virtual void move(double dX, double dY)
        {
            move(Point2D(dX, dY));
        }

        virtual void move(const Point2D &delta) = 0;
        virtual bool isInside(const Point2D &point) const = 0;

        virtual void setCentre(Point2D centre)
        {
        m_centre = centre;
#ifndef NDEBUG
        std::cout << "Circle's centre is set to " << centre << std::endl;
#endif
        transformCoords();
        }


        virtual void setCentre(double x, double y)
        {
            setCentre(Point2D(x, y));
        }
        virtual Point2D centre() const {return m_centre;}
   //painting:
        virtual void paint(QPainter *p) const = 0;

    protected:
        virtual void transformCoords() = 0;
        Point2D m_centre;
        //constructor
        AbstractShape(Point2D centre)
            :m_centre(centre) {}
    };
}
#endif // ABSTRACTSHAPE_H
