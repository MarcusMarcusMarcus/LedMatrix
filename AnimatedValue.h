#pragma once
#include <math.h>
#include <QDateTime>
#include <QGradient>

template<class ValueT>
class AnimatedValue
{
public:
    AnimatedValue(const QList<ValueT> &values,float seconds) :
        m_values(values),
        m_beginTime(0),
        m_endTime(seconds),
        m_startTime(QDateTime::currentDateTime()),
        m_spread(QGradient::RepeatSpread)
    {
    }
    AnimatedValue(const ValueT &from,
                  const ValueT &to,
                  float seconds) :
        AnimatedValue({from,to},seconds)
    {
    }

    void setTimeRange(float begin,float end)
    {
        m_beginTime = begin;
        m_endTime = end;
    }

    float currentTime()
    {
        return m_startTime.msecsTo(QDateTime::currentDateTime()) / 1000.0;
    }

    ValueT value()
    {
        return value(currentTime());
    }

    ValueT value(float time)
    {
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
        return interpolate(m_values[index1],m_values[index2],fraction);
    }

    void setSpread(QGradient::Spread spread)
    {
        m_spread = spread;
    }

protected:
    virtual ValueT interpolate(const ValueT &a,const ValueT &b,float fraction) = 0;

private:
    float m_beginTime;
    float m_endTime;
    QList<ValueT> m_values;
    QDateTime m_startTime;
    QGradient::Spread m_spread;
};

class AnimatedFloat : public AnimatedValue<float>
{
public:
    using AnimatedValue::AnimatedValue;
protected:
    float interpolate(const float &a,const float &b,float fraction) override;
};

class AnimatedColor : public AnimatedValue<QColor>
{
public:
    using AnimatedValue::AnimatedValue;
protected:
    QColor interpolate(const QColor &a,const QColor &b,float fraction) override;
};
