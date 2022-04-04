#include "rhomb.h"
#include<cmath>

Rhomb::Rhomb(double r)
{
    m_r = r;
    m_center_x = 0;
    m_center_y = 0;
    m_S = 2*m_r*m_r;
    m_P = 4*m_r*sqrt(2);
}

void Rhomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->translate(m_center_x*m_scale, m_center_y*m_scale);
    painter->rotate(m_angle);

    QPolygon polygon;
    polygon << QPoint(m_center_x*m_scale,m_center_y*m_scale+m_r*m_scale) << QPoint(m_center_x*m_scale + m_r*m_scale,m_center_y*m_scale)
            << QPoint(m_center_x*m_scale,m_center_y*m_scale-(m_r*m_scale)) << QPoint(m_center_x*m_scale-(m_r*m_scale),m_center_y*m_scale);
    painter->setBrush(Qt::darkGray);
    painter->drawPolygon(polygon);
    QPoint pt(m_center_x*m_scale, m_center_y*m_scale);
    painter->drawPoint(pt);
}

