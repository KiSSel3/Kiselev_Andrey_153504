#ifndef CANVA_H
#define CANVA_H

#include <QWidget>

class canva : public QWidget
{
    Q_OBJECT
    bool isDrawing;
    bool isClicked;
    bool isMoving;
    QVector<QPointF> pointList;
    QPointF movePoint;

public:
    explicit canva(QWidget *parent = nullptr);

    void SetDraw(bool bDraw);

signals:
    void singalDrawOver();

protected:
    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);

    void mouseMoveEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

    void mouseDoubleClickEvent(QMouseEvent *);
};

#endif // CANVA_H
