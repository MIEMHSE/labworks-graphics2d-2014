/**
  @file pie.h
  Определяет сектор круга
*/
#ifndef PIE_H
#define PIE_H

#include "abstractshape.h"
namespace pashazz
{
class Pie : public AbstractShape
{
public:
    Pie(Point2D centre, double radius, double start = 0, double span = M_PI/2)
        :AbstractShape(centre), m_radius(radius), m_start(start), m_span(span) {}
    ~Pie();

    void setStartAngle(double a) {m_start = a;}
    double startAngle() const {return m_start;}

    void setSpanAngle(double a) {m_span = a;}
    double spanAngle() const {return m_span;}

    void setRadius (double r) {m_radius = r;}
    double radius() {return m_radius;}

    bool isInside(const Point2D &point) const;
    void paint(QPainter *p) const;

    void move(const Point2D &delta)
    {
           setCentre(m_centre + delta);
    }


private:
    double m_radius, m_start, m_span;

    static int radiansToDegrees16(double rad);
};

}
#endif // PIE_H
