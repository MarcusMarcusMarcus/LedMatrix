#pragma once
#include <QObject>
#include <QPainter>
#include "LedMatrix.h"

class QPainter;

class Effect : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
    Q_PROPERTY(double opacity READ getOpacity WRITE setOpacity)
public:
    Effect(QObject *parent,int width, int height);
    bool isEnabled();
    void setEnabled(bool value);
    double getOpacity();
    void setOpacity(double value);
    QImage &update();
    void clear();
    int width();
    int height();

    virtual void paint(QPainter &painter) = 0;
private:
    LedMatrix m_matrix;
    QPainter m_painter;
    float m_duration;
    bool m_enabled;
    double m_opacity;
};
