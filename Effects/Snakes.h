#pragma once
#include <QList>
#include <QLinearGradient>
#include "Effect.h"
#include "AnimatedValue.h"

class Snakes : public Effect
{
public:
    Snakes(QObject *parent);
    void paint(QPainter &painter) override;
    void setCount(int count);
    int getCount();
private:
    QList<AnimatedFloat> m_positions;
    QList<QLinearGradient> m_gradients;
};
