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
#include <vector>
#include <memory>

namespace pashazz
{
  typedef std::vector<std::unique_ptr<GraphicsSystemObject*> > GraphicsVector;
  typedef std::vector<GraphcsVector> SystemVector;
    class GraphicsSystemObject
    {
    public:
        GraphicsSystemObject() = delete;
        GraphicsSystemObject(const GraphicsSystemObject&) = delete; //запретить копирование
        GraphicsSystemObject& operator=(const GraphicsSystemObject&) = delete; //и присваивание тоже
        GraphicsSystemObject(AbstractShape *shape, bool sign);
        bool sign () const {return m_sign;}
        bool isInside (const Point2D &p) const;
        void paint(const QPainter &painter);
        ~GraphicsSystemObject() {}

    private:
        AbstractShape *m_pShape;
        bool m_sign;
    };
    class GraphicsSystem
    {
    public:
      GraphicsSystem(const Point2D &centre = {0, 0}, double angle = 0.0)
        :m_centre(centre), m_angle(angle);
      void setPainter(const QPainter &painter);
      void addObject(AbstractShape *shape, bool sign = true, int zOrder = 0);
      void move(double dx, double dy, double dAngle) {move(Point2D(dx, dy), dAngle);}
      void move(const Point2D &delta, double dAngle);
      void rotate(double dAngle);

      //props
      void setAngle(double angle) {m_angle = angle;}
      double angle() const {return m_angle;}

      void setCentre(Point2D centre) {m_centre = centre;}
      Point2D centre() const {return m_centre;}
      //end props
      void paintEvent() const;

      bool isInside(const Point2D &point);
    private:
        SystemVector m_system;
        double m_angle;
        Point2D m_centre;
        QPainter *m_painter;
    };

}


#endif//GRAPHICSSYSTEM_H
