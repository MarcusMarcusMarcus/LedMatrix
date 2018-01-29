#include <math.h>
#include <QDateTime>
#include "AnimatedValue.h"

float AnimatedFloat::interpolate(const float &a,
                                 const float &b,
                                 float fraction)
{
    return a + (b-a) * fraction;
}

QColor AnimatedColor::interpolate(const QColor &a, const QColor &b, float fraction)
{
    return QColor(
                a.red() + (b.red()-a.red()) * fraction,
                a.green() + (b.green()-a.green()) * fraction,
                a.blue() + (b.blue()-a.blue()) * fraction,
                a.alpha() + (b.alpha()-a.alpha()) * fraction);
}
