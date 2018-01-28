#pragma once
#include "Effect.h"

class Clock : public Effect
{
public:
    Clock(QObject *parent);
    void paint(QPainter &painter) override;

};
