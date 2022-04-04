#include "canva.h"

#include <QPainter>
#include <QMouseEvent>

canva::canva(QWidget *parent) : QWidget(parent)
{
    // Заливаем цвет фона
    setAutoFillBackground(true);
    setBackgroundRole(QPalette::Base);

    isDrawing = false;
    isClicked = false;
    isMoving = false;
    setMouseTracking(true);
}

void canva::SetDraw(bool isDrawing)
{
    this->isDrawing = isDrawing;
    pointList.clear();
}

void canva::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if(isDrawing)
    {
       painter.setPen(QColor(0,256,255));
       QVector<QLineF> lines;
       for(int i = 0; i<pointList.size()-1; i++)
       {
           QLineF line(QPointF(pointList[i].x(), pointList[i].y()), QPointF(pointList[i+1].x(), pointList[i+1].y()));
           lines.push_back(line);
       }
       if(isMoving&&pointList.size()>0)
       {
           QLineF line(QPointF(pointList[pointList.size()-1].x(), pointList[pointList.size()-1].y()), movePoint);
           lines.push_back(line);
       }
       painter.drawLines(lines);
    }
}

void canva::mousePressEvent(QMouseEvent *)
{
    if(isDrawing)
    {
        if(!isClicked)
        {
            pointList.clear();
            isClicked = true;
        }
    }
}


void canva::mouseMoveEvent(QMouseEvent *e)
{
    if(isDrawing&&isClicked)
    {
        movePoint = e->pos();
        isMoving = true;
        this->update();
    }
}

void canva::mouseReleaseEvent(QMouseEvent *e)
{
    if(isDrawing&&isClicked)
    {
        pointList.push_back(QPointF(e->x(), e->y()));
        isMoving = false;
        this->update();
    }
}

void canva::mouseDoubleClickEvent(QMouseEvent *)
{
    if(isDrawing)
    {
        isClicked = false;
        pointList.push_back(pointList[0]);
        this->update();
        singalDrawOver();
    }
}
