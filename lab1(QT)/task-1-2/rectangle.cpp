#include "rectangle.h"

Rectangle::Rectangle(double width, double height)
{
    m_width = width;
    m_height = height;
    m_center_x = 0;
    m_center_y = 0;
    m_S = m_width * m_height;
    m_P = (m_width + m_height) * 2;
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPoint(boundingRect().center());
    painter->translate (m_center_x, m_center_y);
    painter->rotate(m_angle);
    painter->setBrush(Qt::darkYellow);
    painter->drawRect(m_center_x*m_scale-(m_width*m_scale / 2),m_center_y*m_scale-(m_height*m_scale / 2),m_width*m_scale,m_height*m_scale);
    QPoint pt(m_center_x*m_scale, m_center_y*m_scale);
    painter->drawPoint(pt);
}
