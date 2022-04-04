#include "oval.h"
#include<cmath>

Oval::Oval(double r1, double r2)
{
    m_radius1 = r1;
    m_radius2 = r2;
    m_center_x = 0;
    m_center_y = 0;
    m_S = M_PI*m_radius1*m_radius2;
    m_P = (M_PI*m_radius1*m_radius2+(m_radius1-m_radius2))/(m_radius1+m_radius2);
}

void Oval::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->rotate(m_angle);
    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(QRectF(m_center_x*m_scale - (m_radius1*m_scale / 2) ,m_center_y*m_scale - (m_radius2*m_scale / 2),m_radius1*m_scale,m_radius2*m_scale));
    QPoint pt(m_center_x*m_scale, m_center_y*m_scale);
    painter->drawPoint(pt);
}
