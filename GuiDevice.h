#pragma once
#include <QApplication>
#include <LedDevice.h>
#include "MainWindow.h"

class GuiDevice : public LedDevice
{
public:
    GuiDevice(int width,int height);
    void paint() override;
private:
    MainWindow m_mainWindow;
};
