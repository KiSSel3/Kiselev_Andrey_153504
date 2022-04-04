#include "star.h"
#include<cmath>

Star::Star(int starTier, int R, int r)
{

    m_R = R;
    m_r = r;
    m_starTier = starTier;
    defSize = R > r ? R : r;
    x = defSize/2;
    y = defSize/2;
    degree = 0;
    p_x = new double[starTier * 2+1];
    p_y = new double[starTier * 2+1];

    m_center_x = 0;
    m_center_y = 0;

    m_S = m_R * m_R * m_starTier * sin(2 * M_PI / m_starTier) / 2;
    m_P = 2 * m_S / m_r;
}

Star::~Star() {
    delete p_x;
    delete p_y;
}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->rotate(m_angle);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::blue);
    double a = 0;
    for (int i=0; i < m_starTier*2; ++i)
    {
     if (!(i%2))
      {
       p_x[i]=x+m_r/2*cos(a*M_PI/180);
       p_y[i]=y-m_r/2*sin(a*M_PI/180);
      }
      else
       {
        p_x[i]=x+m_R*cos(a*M_PI/180);
        p_y[i]=y-m_R*sin(a*M_PI/180);
       }
       a += 180/m_starTier;
    }

    p_x[m_starTier*2]=p_x[0];
    p_y[m_starTier*2]=p_y[0];

    QPainterPath star;
    if (degree) {
        for (int i = 0; i < m_starTier*2+1;++i) {
            p_x[i] = p_x[i]*cos(degree)-p_y[i]*sin(degree);
            p_y[i] = p_x[i]*sin(degree)+p_y[i]*cos(degree);
        }
    }
    star.moveTo(m_center_x*m_scale - p_x[0]*m_scale,m_center_y*m_scale - p_y[0]*m_scale);
    for (int i=0;i<m_starTier*2+1;++i) {
       star.lineTo(m_center_x*m_scale - p_x[i]*m_scale, m_center_y*m_scale - p_y[i]*m_scale);
   }
    painter->drawPath(star);

    QPoint pt(m_center_x*m_scale, m_center_y*m_scale);
    painter->drawPoint(pt);
}


