#pragma once

#include <QList>
#include "Effect.h"
#include "AnimatedPoint.h"
#include "Ball.h"

class Balls : public Effect
{
    Q_OBJECT
    Q_PROPERTY(int count READ getCount WRITE setCount)
public:
    Balls(QObject *parent,int width, int height);
    void paint(QPainter &painter) override;
    void setCount(int count);
    int getCount() const;

private:
    int m_count;
    QList<Ball> m_balls;
    QList<AnimatedPoint> m_points;
};
