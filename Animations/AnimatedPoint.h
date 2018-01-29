#pragma once
#include <QPointF>
#include "AnimatedValue.h"

class AnimatedPoint
{
public:
    AnimatedPoint(QPointF from,QPointF to,
                  float secondsX,float secondsY);

    QPointF value();
    QPointF value(float time);
private:
    AnimatedFloat m_x;
    AnimatedFloat m_y;
};
