#include "MainWindow.h"
#include "GuiDevice.h"
#include "LedMatrix.h"

GuiDevice::GuiDevice(int width, int height) :
    LedDevice(width,height)
{
    m_mainWindow.show();
}

void GuiDevice::paint()
{
    m_mainWindow.paint(matrix());
}
