#pragma once
#include <QMap>
#include <QLinearGradient>
#include "Effect.h"
#include "AnimatedValue.h"
#include "AnimatedPoint.h"

class Snakes : public Effect
{
    Q_OBJECT
    Q_PROPERTY(double count READ getCount WRITE setCount)
    Q_PROPERTY(double span READ getSpan WRITE setSpan)
public:
    struct Snake
    {
        QLinearGradient m_gradients;
        AnimatedPoint m_pos;
        QSizeF m_size;
    };
    Snakes(QObject *parent,int width, int height);
    void paint(QPainter &painter) override;
    void setCount(int count);
    int getCount();
    void setSpan(float value);
    float getSpan();
private:
    void setup();
    void startSnake(int i);
    QColor nextColor();
    AnimatedInt m_index;
    QMap<int,Snake> m_snakes;
    int m_count;
    float m_span;
    int m_lastIndex;
    QColor m_color;
};
