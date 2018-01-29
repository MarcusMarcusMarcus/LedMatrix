#include <QtGlobal>
#include "Random.h"

double Random::getNumber(double min, double max)
{
    double r = double(qrand()) / RAND_MAX;
    return r * (max-min) + min;
}

int Random::getInt(int min, int max)
{
    return qrand() % (max-min+1) + min;
}

QColor Random::getColor()
{
    return QColor::fromRgb(getInt(10,255),getInt(10,255),getInt(10,255));
}

QColor Random::getColor(QColor min, QColor max)
{
    return QColor::fromRgb(getInt(min.red(),max.red()),
                           getInt(min.green(),max.green()),
                           getInt(min.blue(),max.blue()),
                           getInt(min.alpha(),max.alpha()));
}
