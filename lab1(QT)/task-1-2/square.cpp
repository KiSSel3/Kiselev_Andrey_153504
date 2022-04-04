#include "square.h"

Square::Square(double a)
{
    m_a = a;
    m_center_x = 0;
    m_center_y = 0;
    m_S = m_a*m_a;
    m_P = 4*m_a;
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->rotate(m_angle);
    painter->setBrush(Qt::darkMagenta);
    painter->drawRect(m_center_x*m_scale - (m_a*m_scale)/ 2,m_center_y*m_scale - (m_a*m_scale) / 2,m_a*m_scale,m_a*m_scale);
    QPoint pt(m_center_x*m_scale, m_center_y*m_scale);
    painter->drawPoint(pt);
}
