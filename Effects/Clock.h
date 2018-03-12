#pragma once
#include "Effect.h"

class Clock : public Effect
{
public:
    Clock(QObject *parent,int width, int height);
    void paint(QPainter &painter) override;
};
