#pragma once
#include <QObject>

class QPainter;

class Effect : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
public:
    Effect(QObject *parent);
    bool isEnabled();
    void setEnabled(bool value);

    virtual void paint(QPainter &painter) = 0;
private:
    float m_duration;
    bool m_enabled;
};
