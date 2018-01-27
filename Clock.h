#pragma once
#include "Effect.h"

class Clock : public Effect
{
public:
    Clock();
    void paint(QPainter &painter) override;

};
