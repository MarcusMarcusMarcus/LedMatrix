#ifndef WIN32
#include <signal.h>
#include <unistd.h>
#endif
#include "LedMatrix.h"
#include "Ws2811Device.h"

std::unique_ptr<ws2811_t> Ws2811Device::s_leds;

Ws2811Device::Ws2811Device(int width, int height) :
    LedDevice(width,height)
{
#ifndef WIN32
    struct sigaction sa;
    sa.sa_handler = &ctrlHandler;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
#endif
    start(width,height);
}

Ws2811Device::~Ws2811Device()
{
    stop();
}

void Ws2811Device::paint()
{
#ifndef WIN32
    int count = width()*height();
    for(int i=0;i<count;++i)
        s_leds->channel[0].leds[i] = matrix().pixel()[i];
    ws2811_render(s_leds.get());
#endif
}

void Ws2811Device::start(int width,int height)
{
#ifndef WIN32
    stop();
    s_leds.reset(new ws2811_t());
    memset(s_leds.get(),0,sizeof(ws2811_t));
    s_leds->freq = WS2811_TARGET_FREQ;
    s_leds->dmanum = 5;
    s_leds->channel[0].gpionum = 18;
    s_leds->channel[0].count = width*height;
    s_leds->channel[0].invert = 0;
    s_leds->channel[0].brightness = 255;
    s_leds->channel[0].strip_type = WS2811_STRIP_RGB;
    s_leds->channel[1].gpionum = 0;
    s_leds->channel[1].count = 0;
    s_leds->channel[1].invert = 0;
    s_leds->channel[1].brightness = 0;
    s_leds->channel[1].strip_type = 0;
    auto ret = ws2811_init(s_leds.get());
    if (ret != WS2811_SUCCESS)
        exit(0);
#endif
}

void Ws2811Device::stop()
{
#ifndef WIN32
    if (s_leds.get() == nullptr)
        return;
    for(int i=0;i<s_leds->channel[0].count;++i)
        s_leds->channel[0].leds[i] = 0;
    ws2811_render(s_leds.get());
    ws2811_fini(s_leds.get());
    s_leds.reset();
    printf("cleanup\n");
    _exit(0);
#endif
}

void Ws2811Device::ctrlHandler(int)
{
    stop();
}
