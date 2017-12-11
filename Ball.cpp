#include <QPainter>
#include "Ball.h"

Ball::Ball()
{
    setColor(Qt::red);
}


void Ball::paint(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(m_gradient));
    painter.drawEllipse(position(),size(),size());
}

void Ball::setColor(const QColor &color)
{
    m_gradient = QRadialGradient();
    m_gradient.setCenter(0.5,0.5);
    m_gradient.setRadius(0.5);
    m_gradient.setFocalPoint(0.6,0.3);
    m_gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    auto hsl = color.toHsl();
    auto c1 = QColor::fromHslF(hsl.hslHueF(),1,.2);
    auto c2 = QColor::fromHslF(hsl.hslHueF(),1,.4);
    auto c3 = QColor::fromHslF(hsl.hslHueF(),1,.6);
    auto c4 = QColor::fromHslF(hsl.hslHueF(),1,.8);
    m_gradient.setColorAt(0,c4);
    m_gradient.setColorAt(.1,c4);
    m_gradient.setColorAt(.11,c3);
    m_gradient.setColorAt(.8,c2);
    m_gradient.setColorAt(1,c1);
}
