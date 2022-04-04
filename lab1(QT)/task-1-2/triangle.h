#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>

class triangle : public Shape
{

    double m_x1, m_y1, m_x2, m_y2, m_x3, m_y3;
public:

    triangle(double x1 = 0,double y1 = 60, double x2 = 60,double y2 = 0, double x3= 120,double y3 = 60);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TRIANGLE_H
