#include "triangle.h"
#include<cmath>

triangle::triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    m_x1 = x1;
    m_x2 = x2;
    m_x3 = x3;
    m_y1 = y1;
    m_y2 = y2;
    m_y3 = y3;
    m_center_x = (m_x1+ m_x2 + m_x3) / 3;
    m_center_y = (m_y1+ m_y2 + m_y3) / 3;
    sc_center_x = (m_x1+ m_x2 + m_x3) / 3;
    sc_center_y = (m_y1+ m_y2 + m_y3) / 3;

    m_S = 0.5* ((m_x1 - m_x3)*(m_y2 - m_y3)- (m_x2 - m_x3)*(m_y1 - m_y3));
    m_P = sqrt(pow(m_x2 - m_x1,2) + pow(m_y2 - m_y1,2))
        + sqrt(pow(m_x3 - m_x2,2) + pow(m_y3 - m_y2,2))
        + sqrt(pow(m_x3 - m_x1,2) + pow(m_y3 - m_y1,2));
}

void triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->translate(sc_center_x, sc_center_y);
    painter->rotate(m_angle);
    QPolygon polygon;
    polygon << QPoint(m_x1*m_scale,m_y1*m_scale)
            << QPoint(m_x2*m_scale,m_y2*m_scale)
            << QPoint(m_x3*m_scale,m_y3*m_scale);
    painter->setBrush(Qt::darkCyan);
    painter->drawPolygon(polygon);

    QPoint pt(m_center_x*m_scale, m_center_y*m_scale);
    painter->drawPoint(pt);
}
