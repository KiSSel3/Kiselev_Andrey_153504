#ifndef SHAPE_H
#define SHAPE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>

class Shape : public QGraphicsScene, public QGraphicsItem
{
public:
double m_scale = 1;
double m_center_x;
double m_center_y;
double sc_center_x;
double sc_center_y;
double m_S;
double m_P;
int m_angle;
    Shape();
protected:
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) = 0;
    QRectF boundingRect() const;
};

#endif // SHAPE_H
