/**
* @file graphicssystem.h
* @author Pavel Zinin
* @date 3 Dec 2014
*
* Система из геометрических объектов
* Система сама удаляет добавленные объекты в деструкторе
*/
#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include "abstractshape.h"
#include "vector.h"
#include <vector>
#include <memory>
#include <QGraphicsItem>
#include <QBrush>

namespace pashazz
{

    typedef std::vector<std::pair<AbstractShape*, bool>> GraphicsVector;
    typedef std::vector<GraphicsVector> SystemVector;



    class GraphicsSystem : public QGraphicsItem
    {
    public:
        GraphicsSystem(const Point2D &centre = {0, 0}, double angle = 0.0, double height = 0 , double width = 0,
                       QBrush trueBrush = Qt::SolidPattern, QBrush falseBrush = Qt::white);
        ~GraphicsSystem();


        void addObject(AbstractShape *shape, bool sign = true, unsigned int zOrder = 0);
        void move(double dx, double dy, double dAngle) {move(Point2D(dx, dy), dAngle);}
        void move(const Point2D &delta, double dAngle);
        void rotate(double dAngle);

        //props
        void setAngle(double angle) {prepareGeometryChange(); m_angle = angle;}
        double angle() const {return m_angle;}
        void setCentre(Point2D centre) {prepareGeometryChange(); m_centre = centre;}
        Point2D centre() const {return m_centre;}
        //end props

        //Qt drawing methods
        void setSize(double height, double width)
        {
            prepareGeometryChange();
            m_height = height;
            m_width = width;
        }

        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        virtual QRectF boundingRect() const
        {
            return QRectF(-m_height/2, -m_width/2, m_height, m_width);
        }


        bool isInside(const Point2D &point) const;
    private:
        SystemVector m_system;
        Point2D m_centre;
        double m_angle;
        double m_height;
        double m_width;

        QBrush m_trueBrush, m_falseBrush; //brushes which drawing true and false elems
        };

}


#endif//GRAPHICSSYSTEM_H
