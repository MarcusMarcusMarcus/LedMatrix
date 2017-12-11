#pragma once
#include <QPointF>
#include <QSizeF>

class QPainter;

class Shape
{
public:
    Shape();

    void setPosition(const QPointF &point);
    void setSize(float size);

    virtual void paint(QPainter &painter) = 0;

    QPointF position();
    float size();
private:
    QPointF m_position;
    float m_size;
};
