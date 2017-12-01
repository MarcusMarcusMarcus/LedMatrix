#include <math.h>
#include <QDateTime>
#include "AnimatedValue.h"

AnimatedValue::AnimatedValue(float from, float to, float seconds) :
    AnimatedValue({from,to},seconds)
{
}

AnimatedValue::AnimatedValue(const QList<float> &values, float seconds) :
    m_values(values),
    m_beginTime(0),
    m_endTime(seconds),
    m_startTime(QDateTime::currentDateTime()),
    m_spread(QGradient::RepeatSpread)
{

}

void AnimatedValue::setTimeRange(float begin, float end)
{
    m_beginTime = begin;
    m_endTime = end;
}

float AnimatedValue::value()
{
    float time = m_startTime.msecsTo(QDateTime::currentDateTime()) / 1000.0;
    float timeRange = m_endTime - m_beginTime;
    float timeValue = time - m_beginTime;
    switch(m_spread)
    {
    case QGradient::PadSpread:
        if (time < m_beginTime) return m_values.front();
        if (time > m_endTime) return m_values.back();
        break;
    case QGradient::ReflectSpread:
        if (fmod(timeValue,timeRange*2) > timeRange)
            timeValue = timeRange - fmod(timeValue,timeRange);
        break;
    case QGradient::RepeatSpread:
        break;
    }
    int count = m_values.size()-1;
    float pos = fmod(timeValue,timeRange) / timeRange * count;
    float fraction = fmod(pos,1.0);
    int index1 = int(pos);
    int index2 = int(pos)+1;
    if (index1 >= count)
        return m_values.back();
    float value = m_values[index1] + (m_values[index2]-m_values[index1]) * fraction;
//    printf("%f %f %f\n",pos,fraction,value);
    return value;
}
