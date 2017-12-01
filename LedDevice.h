#pragma once
#include <QCoreApplication>
#include <QTimer>
#include "LedMatrix.h"

class LedDevice
{
public:
    LedDevice(int width,int height);
    virtual ~LedDevice();

    int width();
    int height();
    LedMatrix &matrix();
    virtual void paint() = 0;

    void start(float interval);
    void update();

protected:
    void setSize(int width,int height);

private:
    int m_width;
    int m_height;
    LedMatrix m_matrix;
    QTimer m_timer;
};
