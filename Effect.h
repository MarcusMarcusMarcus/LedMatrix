#pragma once

class QPainter;

class Effect
{
public:
    Effect();
    virtual void paint(QPainter &painter) = 0;
private:
    float m_duration;
};
