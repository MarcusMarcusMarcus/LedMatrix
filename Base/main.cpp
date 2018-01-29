#ifdef WIN32
#include <Windows.h>
#endif
#include <memory>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QTextStream>
#include <QDebug>
#include "LedMatrix.h"
#include "GuiDevice.h"
#include "Ws2811Device.h"

int main(int argc, char *argv[])
{
#ifdef WIN32
    if (AttachConsole(ATTACH_PARENT_PROCESS) ||
        AllocConsole())
    {
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }
#endif
    QApplication application(argc,argv);
    QCommandLineParser parser;
    parser.addOption(QCommandLineOption({"W","width"},"LED matrix width","width","22"));
    parser.addOption(QCommandLineOption({"H","height"},"LED matrix width","height","22"));
    parser.addOption(QCommandLineOption({"d","device"},"Device (gui/ws2811)","device","gui"));
    parser.addOption(QCommandLineOption({"c","command"},"script commands","command",""));
    auto helpOption = parser.addHelpOption();
    if (!parser.parse(qApp->arguments()))
    {
        QTextStream(stdout) << parser.errorText() << endl;
        return 0;
    }
    if (parser.isSet(helpOption))
        parser.showHelp(0);

    std::unique_ptr<LedDevice> device;
    int width = parser.value("width").toInt();
    int height = parser.value("height").toInt();

    if (parser.value("device") == "gui")
    {
        device.reset(new GuiDevice(width,height));
    }
    else
    {
        qputenv("QT_QPA_PLATFORM","offscreen");
        device.reset(new Ws2811Device(width,height));
    }

    if (parser.isSet("command"))
    {
        QScriptValue result = device->scriptEngine().evaluate(parser.value("command"));
        if (result.isError())
            return 0;
        qDebug() << parser.value("command");
        qDebug() << result.toString();
    }

    device->paint();
    device->start(0.05);
    application.exec();
    return 0;
}
