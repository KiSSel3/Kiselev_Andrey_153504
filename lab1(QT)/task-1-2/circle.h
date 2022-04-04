#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <QGraphicsScene>
#include <QMainWindow>
#include <QGraphicsItem>
#include <QPainter>

class Circle : public Shape
{
    double m_radius;

public:
    Circle(double radius = 80);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // CIRCLE_H
