#ifndef RHOMB_H
#define RHOMB_H

#include "shape.h"
#include <QPainter>
#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Rhomb : public Shape
{
    double m_r;

public:
    Rhomb(double r = 60);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RHOMB_H
