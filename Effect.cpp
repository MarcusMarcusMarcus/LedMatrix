#include "Effect.h"

Effect::Effect(QObject *parent) :
    QObject(parent),
    m_enabled(false)
{
}

bool Effect::isEnabled()
{
    return m_enabled;
}

void Effect::setEnabled(bool value)
{
    m_enabled = value;
}
