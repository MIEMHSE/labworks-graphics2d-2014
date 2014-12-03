/**
* @file graphicssystem.h
* @author Pavel Zinin
* @date 3 Dec 2014
*
* Система из геометрических объектов
*/
#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include "abstractshape.h"
#include "vector.h"


namespace pashazz
{
    class GraphicsSystemObject
    {
    public:
        GraphicsSystemObject() = delete;
        GraphicsSystemObject(const GraphicsSystemObject&) = delete; //запретить копирование
        GraphicsSystemObject& operator=(const T& other) = delete; //и присваивание тоже
        GraphicsSystemObject(AbstractShape *shape, QPainter painter,  offset = {0, 0});
        Point2D offset() const {return m_offset;}
        void setOffset(Point2D offset);
        bool isInside (const Point2D &p) const;


    private:
        AbstractShape *m_pShape;
    };
    class GraphicsSystem
    {
    public:
        GraphicsSystem();

    };

}


#endif//GRAPHICSSYSTEM_H