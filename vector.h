/** @file vector.h
* Класс точки на плоскости. Она же вектор из начала координат
*
* Наша система координат (Cartesian) - у направлен вверх, x - вправо.
*
*
*
*/

#ifndef VECTOR_H
#define VECTOR_H
#include <math.h>
#include <ostream>
#include <QPointF>


using std::ostream;

namespace pashazz
{


    class Point2D
    {
    public:
        Point2D(double x = 0, double y = 0)
                : x(x), y(y)
        {
        }

        double x;
        double y;

        Point2D &operator+=(const Point2D &rvalue)
        {
            x += rvalue.x;
            y += rvalue.y;
            return *this;
        }

        Point2D &operator-=(const Point2D &rvalue)
        {
            x -= rvalue.x;
            y -= rvalue.y;
            return *this;
        }

        Point2D &operator*=(double rvalue)
        {
            x *= rvalue;
            y *= rvalue;
            return *this;
        }

        Point2D operator/=(double rvalue)
        {
            x /= rvalue;
            y /= rvalue;
            return *this;
        }

        bool operator==(const Point2D &rvalue) const
        {
            return x == rvalue.x && y == rvalue.y;
        }

        bool operator!=(const Point2D &rvalue) const
        {
            return !operator==(rvalue);
        }

        Point2D operator-() const
        {
            return Point2D(-x, -y);
        }

        double length() const
        {
            return sqrt(x * x + y * y);
        }

        /**
    * @brief вращает точку вокруг начала координат
    *
    * Вычисление определителя матрицы поворота точки вокруг угла angle вокруг часовой стрелки
    *
    * @param angle - угол в радианах
    * @return новые координаты точки
    *
    *
    * */
        Point2D rotate (double angle) const
        {
#ifndef NDEBUG
            std::cout << "Rotating " << *this << " around the start by angle " << angle << "radians. New coords: "
                      << Point2D(cos(angle) * x - sin(angle) * y, sin(angle) * x + cos(angle) * y) << std::endl;
#endif
            return
                    Point2D(
                        cos(angle) * x - sin(angle) * y,
                        sin(angle) * x + cos(angle) * y
                        );
        }

        /**
          @brief вращает координаты

          вращает координаты на угол angle, возвращает координаты точки в новой системе

          @param angle - угол в радианах
          @return новые координаты точки
         **/

        Point2D rotateAxis (double angle) const
        {
            return Point2D (
                        cos(angle) * x + sin(angle) * y,
                        cos(angle) * y - sin(angle) * x
                        );
        }

        /**
        * @brief возвращает координаты точки в новой системе с центром в данной
        *
        */
        Point2D translate (Point2D p) const
        {
            return Point2D(p.x - x, p.y - y);
        }

        friend double operator*(const Point2D &lvalue, const Point2D &rvalue)
        {
            return lvalue.x * rvalue.x+
                    lvalue.y * rvalue.y;
        }


        friend Point2D operator* (const Point2D &lvalue, double rvalue)
        {
            Point2D r = lvalue;
            return r *= rvalue;
        }

        friend Point2D operator* (double lvalue, const Point2D &rvalue)
        {
            return operator*(rvalue, lvalue);
        }

        friend Point2D operator/ (const Point2D &lvalue, double rvalue)
        {
            Point2D r = lvalue;
            return r /= rvalue;
        }


        friend Point2D operator+ (const Point2D &lvalue, const Point2D &rvalue)
        {
            Point2D r = lvalue;
            return r += rvalue;
        }

        friend Point2D operator-(const Point2D &lvalue, const Point2D &rvalue)
        {
            Point2D r = lvalue;
            return r -= lvalue;
        }

        friend bool operator<(const Point2D &lvalue, const Point2D &rvalue)
        {
            return lvalue.x * lvalue.x + lvalue.y * lvalue.y <
                    rvalue.y * rvalue.y + rvalue.y * rvalue.y; //x^2+y^2 < x_2^2-y_2^2
        }

        friend bool operator<=(const Point2D &lvalue, const Point2D &rvalue)
        {
            return lvalue < rvalue || lvalue == rvalue;
        }

        friend bool operator>(const Point2D &lvalue, const Point2D &rvalue)
        {
            return !(lvalue <= rvalue);
        }

        friend bool operator>=(const Point2D &lvalue, const Point2D &rvalue)
        {
            return !(lvalue < rvalue);
        }

        /*
    @brief возвращает угол (в радианах), относительно оси x
     */
        double angle()
        {
            return atan2(y, x);
        }

        friend ostream &operator<<(ostream &stream, const Point2D &rvalue)
        {
            stream << "[" << rvalue.x << "],[" << rvalue.y << "]";
            return stream;
        }

        /* конвертация в QPointF */
        operator QPointF() const
        {
            return QPointF(x, y);
        }
    };

}
#endif //VECTOR_H
