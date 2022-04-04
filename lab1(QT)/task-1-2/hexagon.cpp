#include "hexagon.h"
#include<cmath>

Hexagon::Hexagon(double r)
{
    m_r = r;
    m_N = 6;
    angle = 0;
    arr_points_x = new double[m_N+1];
    arr_points_y = new double[m_N+1];
    m_S = 3*sqrt(3)*m_r*m_r/2.0;
    m_P = 6*m_r;
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->translate(m_center_x,m_center_y);
    painter->rotate(m_angle);
    painter->setBrush(Qt::cyan);

    for (int i=0; i<m_N+1; ++i){
        arr_points_x[i] = m_r * cos(angle * M_PI/180);
        arr_points_y[i] = m_r * sin(angle * M_PI/180);
        angle = angle + 360.0/m_N;
    }

    QPainterPath hex;
    hex.moveTo(arr_points_x[0]*m_scale, arr_points_y[0]*m_scale);
    for (int i=0;i<m_N+1;++i) {
        hex.lineTo(arr_points_x[i]*m_scale , arr_points_y[i]*m_scale);
    }

    painter->drawPath(hex);
    QPoint pt(m_center_x*m_scale, m_center_y*m_scale);
    painter->drawPoint(pt);
}
