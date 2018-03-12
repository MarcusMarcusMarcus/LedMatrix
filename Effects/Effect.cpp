#include <QPainter>
#include "Effect.h"

Effect::Effect(QObject *parent,int width, int height) :
    QObject(parent),
    m_enabled(false),
    m_matrix(width,height),
    m_painter(&m_matrix.image()),
    m_opacity(1)
{
    clear();
    m_painter.setBackground(QBrush(QColor(0,0,0,255)));
}

bool Effect::isEnabled()
{
    return m_enabled;
}

void Effect::setEnabled(bool value)
{
    m_enabled = value;
}

double Effect::getOpacity()
{
    return m_opacity;
}

void Effect::setOpacity(double value)
{
    m_opacity = value;
}

QImage &Effect::update()
{
    paint(m_painter);
    return m_matrix.image();
}

void Effect::clear()
{
    m_matrix.image().fill(QColor(0,0,0,0));
}

int Effect::width()
{
    return m_matrix.width();
}

int Effect::height()
{
    return m_matrix.height();
}
