#ifndef OVAL_H
#define OVAL_H

#include "shape.h"

class Oval : public Shape
{
public:
    double m_radius1;
    double m_radius2;


    Oval(double radius1 =160, double radius2 = 90);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // OVAL_H
