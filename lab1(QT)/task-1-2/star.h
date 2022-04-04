#ifndef STAR_H
#define STAR_H

#include "shape.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>

class Star : public Shape
{
    Q_OBJECT

private:
    int m_R, m_r, m_starTier;
    double degree;
    double defSize, size;
    double *p_x, *p_y;
    double x, y;

public:
    Star(int starTier = 5, int R = 100, int r = 50);
    ~Star();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STAR_H
