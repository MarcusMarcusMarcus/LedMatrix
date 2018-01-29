#include "AnimatedPoint.h"

AnimatedPoint::AnimatedPoint(QPointF from, QPointF to,
                             float secondsX, float secondsY) :
    m_x(from.x(),to.x(),secondsX),
    m_y(from.y(),to.y(),secondsY)
{
    m_x.setSpread(QGradient::ReflectSpread);
    m_y.setSpread(QGradient::ReflectSpread);
}

QPointF AnimatedPoint::value()
{
    return value(m_x.currentTime());
}

QPointF AnimatedPoint::value(float time)
{
    return QPointF(m_x.value(time),m_y.value(time));
}
