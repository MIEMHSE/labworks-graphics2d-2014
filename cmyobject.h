/**
* @file cmyobject.h
* @date 11 Dec 2014
* @author Pavel Zinin
*/
#ifndef CMYOBJECT_H
#define CMYOBJECT_H

#include "graphicssystem.h"
#include <QGraphicsScene>
#include <QBrush>
#include "square.h"
#include "circle.h"
#include "scene.h"
#include "string"

namespace  pashazz
{
    /**
     * @class CMyObjectA2
     * Описывает объект типа коллекции фигур
     * если определить NO_INTERSECTION, вызывает std::invalid_argument при самопересечении границ
     *
     */
    //#define NO_INTERSECTION


    class CMy2DObjectA2
    {

    public:
        CMy2DObjectA2(Point2D centre, double edge, double radius1, double radius2, double radius3, double angle, QBrush background = Qt::NoBrush, QBrush foreground = Qt::SolidPattern);
        ~CMy2DObjectA2();
        //Property begin
        //С.Аксенов настаивает на PascalCase нотации

        void SetCentre(const Point2D &centre) {m_centre = centre;}
        Point2D GetCentre() const {return m_centre;}

        void SetEdge(double);
        double GetEdge() const;

        void SetRadius1(double);
        double GetRadius1() const;

        void SetRadius2(double);
        double GetRadius2() const;

        void SetRadius3(double);
        double GetRadius3() const;

        void SetAngle(double angle);
        double GetAngle() const;

        pashazz::GraphicsScene* GetScene() const {return scene;}
        bool IsInside(const Point2D &point) const {sys->isInside(point);}

        void Rotate(double dAngle);

    private:
        /**
         * @brief updateScene
         * Обновляет позиции фигур относительно главного квадрата. Вызывать после изменения стороны главного квадрата
         */
        void updateScene();

        /**
        * @brief проверяет границы фигуры
        * @param message - записывает сообщение в message для передачи уровнем выше
        */
        bool checkIntersection(std::string &) const;
        void throwIntersection() const;

        //fields
        Point2D m_centre;
        pashazz::GraphicsSystem *sys;
        /* фигуры */
        pashazz::Square *square, *minisquare;
        pashazz::Circle *circle1, *circle2, *circle3;
        pashazz::GraphicsScene *scene;
        QBrush m_background, m_foreground;
    };


}

#endif //CMYOBJECT_H
