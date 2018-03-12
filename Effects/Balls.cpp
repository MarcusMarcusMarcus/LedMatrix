#include "Random.h"
#include "Balls.h"

Balls::Balls(QObject *parent, int width, int height) :
    Effect(parent,width,height)
{
    setCount(5);
}

void Balls::paint(QPainter &painter)
{
    for(int i=0;i<m_balls.size();++i)
    {
        m_balls[i].setPosition(m_points[i].value());
        m_balls[i].paint(painter);
    }
}

void Balls::setCount(int count)
{
    m_count = count;
    m_balls.clear();
    m_points.clear();
    for(int i=0;i<count;++i)
    {
        m_balls.push_back(Ball());
        m_balls.back().setColor(Random::getColor());
        m_balls.back().setSize(Random::getInt(2,6));
        m_points.push_back(AnimatedPoint(
                            {0,0},
                            {22,22},
                            Random::getNumber(0.5,2.0),
                            Random::getNumber(0.5,2.0)));
    }
}

int Balls::getCount() const
{
    return m_count;
}
