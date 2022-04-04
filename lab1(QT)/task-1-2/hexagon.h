#ifndef HEXAGON_H
#define HEXAGON_H

#include "shape.h"

class Hexagon : public Shape
{
   double m_r;
   int m_N;
   double angle;
   double *arr_points_x;
   double *arr_points_y;

public:
    Hexagon(double r = 100);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // HEXAGON_H
