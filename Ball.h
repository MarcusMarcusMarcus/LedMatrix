#pragma once

#include <QRadialGradient>
#include <Shape.h>

class Ball : public Shape
{
public:
    Ball();

    void paint(QPainter &painter) override;
    void setColor(const QColor &color);
private:
    QRadialGradient m_gradient;
};
