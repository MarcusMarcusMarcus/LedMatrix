#include <QDateTime>
#include "AnimatedValue.h"

AnimatedValue::AnimatedValue(float from, float to, float seconds) :
    m_from(from),
    m_to(to),
    m_start(0),
    m_stop(seconds),
    m_seconds(seconds),
    m_startTime(QDateTime::currentDateTime()),
    m_spread(QGradient::RepeatSpread)
{
}

float AnimatedValue::value()
{
    float time = m_startTime.msecsTo(QDateTime::currentDateTime()) / 1000.0;
    float valueRange = m_to - m_from;
    float timeRange = m_stop - m_start;
    float timeValue = time - m_start;
    float timeFraction;
    switch(m_spread)
    {
    case QGradient::PadSpread:
        if (time < m_start) return m_from;
        if (time > m_stop) return m_to;
        break;
    case QGradient::ReflectSpread:
        if (fmod(timeValue,timeRange*2) > timeRange)
            timeValue = timeRange - fmod(timeValue,timeRange);
        break;
    case QGradient::RepeatSpread:
        break;
    }
    timeFraction = fmod(timeValue,timeRange);
    return timeFraction / timeRange * valueRange;
}
