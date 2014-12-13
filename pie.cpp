#include "pie.h"

using namespace pashazz;
Pie::~Pie()
{

}

bool Pie::isInside(const Point2D &point) const
{
   Point2D priv_point = m_centre.translate(point);
   double pAngle = priv_point.angle();
   return  (pAngle > m_start || pAngle < m_span) && priv_point.length() <= m_radius;
}

void Pie::paint(QPainter *p) const
{
    QRectF rect(m_centre+Point2D(m_radius,m_radius), m_centre-Point2D(m_radius, m_radius));
    p->drawPie(rect, radiansToDegrees16(m_start), radiansToDegrees16(m_span));
}

int inline Pie::radiansToDegrees16(double rad)
{
   return (int)(rad * 2880 /*180*16 */ / M_PI);
}
