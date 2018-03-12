#pragma once

#include <QColor>

class Random
{
public:
    static double getNumber(double min,double max);
    static int getInt(int min,int max);
    static bool getBool();
    static QColor getColor();
    static QColor getColor(QColor min,QColor max);
};
