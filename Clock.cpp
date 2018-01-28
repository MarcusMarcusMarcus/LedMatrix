#define _USE_MATH_DEFINES
#include <cmath>
#include <QDateTime>
#include <QPainter>

#include "Clock.h"

Clock::Clock(QObject *parent) :
    Effect(parent)
{
}

void Clock::paint(QPainter &painter)
{
    auto time = QDateTime::currentDateTime().time();

    auto h = M_PI * (-.5 + 2*fmod(time.msecsSinceStartOfDay() / float(1000*60*60*12),1));
    auto m = M_PI * (-.5 + 2*time.minute() / float(60));
    auto s = M_PI * (-.5 + 2*time.second() / float(60));
    float x = painter.window().width() / 2.0 ;
    float y = painter.window().height() / 2.0 ;
    float r = std::min(x,y) - 1;
    float hr = r * .6;
    float mr = r * .8;
    float sr = r * .8;

    QPen pen;
    pen.setWidth(2);
    pen.setCapStyle(Qt::RoundCap);
    pen.setColor(QColor::fromRgb(255,127,0));
    painter.setPen(pen);
    for(double a = 0 ; a<2*M_PI ; a+=M_PI/6)
        painter.drawPoint(QPointF(cos(a)*r+x,sin(a)*r+y));
    pen.setWidth(2);
    pen.setColor(QColor::fromRgb(255,32,0));
    painter.setPen(pen);
    for(double a = 0 ; a<2*M_PI ; a+=M_PI/2)
        painter.drawPoint(QPointF(cos(a)*r+x,sin(a)*r+y));

    /*
    painter.drawArc(QRect(1,1,x*2-2,y*2-2),90*16,-360*16*h);
    pen.setColor(Qt::green);
    painter.setPen(pen);
    painter.drawArc(QRect(3,3,x*2-6,y*2-6),90*16,-360*16*m);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    painter.drawArc(QRect(5,5,x*2-10,y*2-10),90*16,-360*16*s);
    */

    pen.setWidthF(2.5);
    pen.setColor(QColor::fromRgb(64,255,0));
    painter.setPen(pen);
    painter.drawLine(QPointF(x,y),QPointF(cos(h)*hr+x,sin(h)*hr+y));

    pen.setColor(QColor::fromRgb(32,127,0));
    pen.setWidthF(1.5);
    painter.setPen(pen);
    painter.drawLine(QPointF(x,y),QPointF(cos(m)*mr+x,sin(m)*mr+y));

    pen.setColor(QColor::fromRgb(64,64,255));
    pen.setWidthF(2);
    painter.setPen(pen);
    painter.drawPoint(QPointF(cos(s)*sr+x,sin(s)*sr+y));
/*
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawLine(x,y,cos(s)*sr+x,sin(s)*sr+y);
    */
}
