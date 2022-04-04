#include "shape.h"

Shape::Shape()
{

}

void Shape::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *)
{

}

QRectF Shape::boundingRect() const
{
    return (QRect(-240, -180, 610, 460));
}
