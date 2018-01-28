#pragma once
#include <QCoreApplication>
#include <QScriptEngine>
#include <QTimer>
#include "LedMatrix.h"

class Effect;

class LedDevice : QObject
{
    Q_OBJECT
public:
    LedDevice(int width,int height);
    virtual ~LedDevice();

    int width();
    int height();
    LedMatrix &matrix();
    virtual void paint() = 0;

    void start(float interval);
    void update();
    QScriptEngine &scriptEngine();

protected:
    void setSize(int width,int height);

private:
    int m_width;
    int m_height;
    LedMatrix m_matrix;
    QTimer m_timer;
    QScriptEngine m_scriptEngine;
    QMap<QString,Effect*> m_effects;
};
