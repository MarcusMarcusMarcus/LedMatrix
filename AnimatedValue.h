#pragma once
#include <QDateTime>
#include <QGradient>

class AnimatedValue
{
public:
    AnimatedValue(float from,float to,float seconds);
    AnimatedValue(const QList<float> &values,float seconds);

    void setTimeRange(float begin,float end);

    float value();
private:
    float m_beginTime;
    float m_endTime;
    QList<float> m_values;
    QDateTime m_startTime;
    QGradient::Spread m_spread;
};
