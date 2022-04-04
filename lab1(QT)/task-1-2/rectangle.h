#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

#include <QPainter>
#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Rectangle : public Shape
{
    double m_width;
    double m_height;
public:
    Rectangle(double width = 160, double height = 80);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECTANGLE_H
