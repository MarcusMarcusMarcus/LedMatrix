#include <QDateTime>
#include <QPainter>
#include "LedDevice.h"

#include <QBrush>

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
    gradient.setColorAt(0,QColor(Qt::red));
    gradient.setColorAt(.25,QColor(Qt::yellow));
    gradient.setColorAt(.5,QColor(Qt::green));
    gradient.setColorAt(.75,QColor(Qt::blue));
    gradient.setColorAt(1,QColor(Qt::red));
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
    static int offset = 1;
    offset++;
    QRadialGradient gradient(11,11,22);
    gradient.setColorAt(0,QColor(Qt::red));
    gradient.setColorAt(.25,QColor(Qt::yellow));
    gradient.setColorAt(.5,QColor(Qt::green));
    gradient.setColorAt(.75,QColor(Qt::blue));
    gradient.setColorAt(1,QColor(Qt::red));
    gradient.setSpread(QGradient::RepeatSpread);
    gradient.setRadius(offset);
    gradient.setFocalPoint(1,1);
//    gradient.setCenterRadius(offset);
    QBrush brush(gradient);
    painter.setBrush(brush);
    painter.fillRect(0,0,width,height,gradient);
    painter.end();
}

void LedDevice::update()
{
    QPainter painter(&matrix().image());
    test2(painter,width(),height());

    printf("%s\n",QDateTime::currentDateTime().toString().toUtf8().constData());
    paint();
}
