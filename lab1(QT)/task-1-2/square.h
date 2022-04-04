#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>

class Square : public Shape
{
    double m_a;
public:
    Square(double a = 80);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SQUARE_H
