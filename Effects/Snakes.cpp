#include <QLinearGradient>
#include <QPainter>
#include "Snakes.h"
#include "Random.h"
#include "AnimatedValue.h"

Snakes::Snakes(QObject *parent) :
    Effect(parent)
{
}

void Snakes::paint(QPainter &painter)
{
    static QLinearGradient gradient;
    gradient.setColorAt(0,Random::getColor());
    gradient.setColorAt(1,Random::getColor());
    gradient.setSpread(QGradient::RepeatSpread);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    static AnimatedFloat value({-22,22},.5);

//    QBrush brush(gradient);
//    painter.setBrush(brush);
    painter.fillRect(value.value(),0,22,22,gradient);





}

void Snakes::setCount(int count)
{
    m_positions.clear();
    m_gradients.clear();
    for(int i=0;i<count;++i)
    {
        m_gradients.push_back(QLinearGradient());
//        m_positions.push_back();
        m_gradients.back().setColorAt(0,Random::getColor());
        m_gradients.back().setColorAt(1,Random::getColor());
        m_gradients.back().setSpread(QGradient::RepeatSpread);
        m_gradients.back().setCoordinateMode(QGradient::ObjectBoundingMode);

    }

}

int Snakes::getCount()
{
    return m_gradients.size();
}
