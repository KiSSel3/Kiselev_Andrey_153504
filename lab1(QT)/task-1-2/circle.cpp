#include "circle.h"
#include<cmath>

Circle::Circle(double radius)
{
    m_radius = radius;
    m_center_x = 0;
    m_center_y = 0;
    m_P = 2 * M_PI * m_radius;
    m_S = M_PI * m_radius * m_radius;
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);


    painter->rotate(m_angle);
    painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(QRectF(m_center_x*m_scale - m_radius*m_scale / 2,m_center_y*m_scale - m_radius*m_scale / 2,
                                m_radius*m_scale,m_radius*m_scale));

    QPoint pt(m_center_x*m_scale, m_center_y*m_scale);
    painter->drawPoint(pt);
}
