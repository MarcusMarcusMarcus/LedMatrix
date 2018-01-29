#include "Shape.h"

Shape::Shape() :
    m_position(0,0),
    m_size(1)
{
}

void Shape::setPosition(const QPointF &point)
{
    m_position = point;
}

void Shape::setSize(float size)
{
    m_size = size;
}

QPointF Shape::position()
{
    return m_position;
}

float Shape::size()
{
    return m_size;
}
