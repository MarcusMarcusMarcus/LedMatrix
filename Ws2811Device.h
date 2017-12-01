#pragma once
#include <memory>
#include <QCoreApplication>
#include "LedDevice.h"
#ifndef WIN32
#include <ws2811/ws2811.h>
#else
struct ws2811_t {};
#endif

class Ws2811Device : public LedDevice
{
public:
    Ws2811Device(int width,int height);
    ~Ws2811Device();

    void paint() override;

private:
    static void start(int width, int height);
    static void stop();
    static void ctrlHandler(int);

    static std::unique_ptr<ws2811_t> s_leds;
};
