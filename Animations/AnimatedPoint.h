#pragma once
#include <QPointF>
#include "AnimatedValue.h"

class AnimatedPoint
{
public:
    AnimatedPoint(QPointF from = QPointF(0,0),
                  QPointF to = QPointF(0,0),
                  float secondsX = 1,
                  float secondsY = 1);

    QPointF value();
    QPointF value(float time);
private:
    AnimatedFloat m_x;
    AnimatedFloat m_y;
};
