#include <QLinearGradient>
#include <QPainter>
#include "Snakes.h"
#include "Random.h"
#include "AnimatedValue.h"

Snakes::Snakes(QObject *parent, int width, int height) :
    Effect(parent,width,height),
    m_count(1),
    m_color()
{
    setCount(20);
    setSpan(2);
    m_color = QColor(Qt::red);
}

void Snakes::paint(QPainter &painter)
{
    int index = m_index.value();
    if (index != m_lastIndex)
        startSnake(index);
    m_lastIndex = index;

    for(auto &snake : m_snakes.values())
    {
        painter.fillRect(QRectF(snake.m_pos.value(),
                                snake.m_size),
                         snake.m_gradients);
    }
}

void Snakes::setCount(int count)
{
    m_count = count;
    setup();
}

int Snakes::getCount()
{
    return m_count;
}

void Snakes::setSpan(float value)
{
    m_span = value;
    setup();
}

float Snakes::getSpan()
{
    return m_span;
}

void Snakes::setup()
{
    m_lastIndex = -1;
    m_index = AnimatedInt(0,m_count-1,m_span);
    m_snakes.clear();
    clear();
}

void Snakes::startSnake(int i)
{
    QLinearGradient gradient;
    auto color = nextColor();
//    gradient.setColorAt(0,Random::getColor());
//    gradient.setColorAt(1,Random::getColor());
    gradient.setColorAt(0,color.lighter(0));
    gradient.setColorAt(1,color.darker(400));
    gradient.setSpread(QGradient::RepeatSpread);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    AnimatedPoint point;
    QSizeF size;

    int dir = Random::getBool() ? 1 : -1;

    float speed = m_span;

    if (Random::getBool())
    {
        int location = Random::getInt(0,width()-1);
        point = AnimatedPoint(QPointF(-width()*dir,location),
                              QPointF(width()*dir,location),speed);
        size = QSizeF(width(),1);
    }
    else
    {
        int location = Random::getInt(0,height()-1);
        point = AnimatedPoint(QPointF(location,-height()*dir),
                              QPointF(location,height()*dir),0,speed);
        size = QSizeF(1,height());
    }
    m_snakes[i] = Snake{gradient,point,size};
}

QColor Snakes::nextColor()
{
    if (!m_color.isValid())
        return Random::getColor();
    return m_color;
}
