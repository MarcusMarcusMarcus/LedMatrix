#include <QDateTime>
#include <QPainter>
#include <QBrush>
#include "LedDevice.h"
#include "AnimatedValue.h"
#include "AnimatedPoint.h"
#include "Ball.h"

LedDevice::LedDevice(int width, int height) :
    m_matrix(width,height),
    m_width(width),
    m_height(height)
{
}

LedDevice::~LedDevice()
{
}

int LedDevice::width()
{
    return m_width;
}

int LedDevice::height()
{
    return m_height;
}

LedMatrix &LedDevice::matrix()
{
    return m_matrix;
}

void LedDevice::start(float interval)
{
    m_timer.setInterval(int(interval*1000));
    m_timer.connect(&m_timer,&QTimer::timeout,[this]{update();});
    m_timer.start();
}


void test1(QPainter &painter,int width,int height)
{
    static int offset = 1;
    offset++;
    QLinearGradient gradient;
    gradient.setColorAt(0,QColor(qRgb(63,0,0)));
    gradient.setColorAt(.25,QColor(qRgb(63,63,0)));
    gradient.setColorAt(.5,QColor(qRgb(0,63,0)));
    gradient.setColorAt(.75,QColor(qRgb(0,0,63)));
    gradient.setColorAt(1,QColor(qRgb(63,0,0)));
    gradient.setSpread(QGradient::RepeatSpread);
    gradient.setStart(0+offset,0+offset);
    gradient.setFinalStop(122+offset,122+offset);
    QBrush brush(gradient);
    painter.setBrush(brush);
    painter.fillRect(0,0,width,height,gradient);
    painter.end();
}

void test2(QPainter &painter,int width,int height)
{
    static AnimatedFloat offset({10.0,33.0},10);
    static AnimatedFloat focal(0,22,5);
    QRadialGradient gradient(11,11,22);
#if 0
    gradient.setColorAt(0,QColor(Qt::red));
    gradient.setColorAt(.25,QColor(Qt::yellow));
    gradient.setColorAt(.5,QColor(Qt::green));
    gradient.setColorAt(.75,QColor(Qt::blue));
    gradient.setColorAt(1,QColor(Qt::red));
#else
    gradient.setColorAt(0,QColor(qRgb(31,0,0)));
    gradient.setColorAt(.25,QColor(qRgb(31,31,0)));
    gradient.setColorAt(.5,QColor(qRgb(0,31,0)));
    gradient.setColorAt(.75,QColor(qRgb(0,0,31)));
    gradient.setColorAt(1,QColor(qRgb(31,0,0)));
#endif
    gradient.setSpread(QGradient::RepeatSpread);
    gradient.setRadius(offset.value());
    gradient.setFocalPoint(focal.value(),focal.value());
    //    gradient.setCenterRadius(offset.value());
    QBrush brush(gradient);
    painter.setBrush(brush);
    painter.fillRect(0,0,width,height,gradient);
    painter.end();
}

void test3(QPainter &painter,int width,int height)
{
    static AnimatedPoint point1({0,0},{22,22},11,1.5);
    static AnimatedPoint point2({0,0},{22,22},1.4,1.9);
    static AnimatedPoint point3({0,0},{22,22},.7,.62324);

    Ball ball1;
    ball1.setColor(Qt::red);
    ball1.setPosition(point1.value());
    ball1.setSize(4);
    ball1.paint(painter);
    Ball ball2;
    ball2.setColor(QColor(255,127,0));
    ball2.setPosition(point2.value());
    ball2.setSize(5);
    ball2.paint(painter);
    painter.end();
}

void LedDevice::update()
{
  matrix().image().fill(Qt::black);
    QPainter painter(&matrix().image());
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
  //  painter.setCompositionMode(QPainter::CompositionMode_Plus);
   
    
    test3(painter,width(),height());

    //    printf("%s\n",QDateTime::currentDateTime().toString().toUtf8().constData());
    paint();
}
