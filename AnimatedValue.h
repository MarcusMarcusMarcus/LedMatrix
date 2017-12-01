#pragma once
#include <QDateTime>
#include <QGradient>

class AnimatedValue
{
public:
    AnimatedValue(float from,float to,float seconds);

    float value();
private:
    float m_from;
    float m_to;
    float m_seconds;
    float m_start;
    float m_stop;
    QDateTime m_startTime;
    QGradient::Spread m_spread;
};
