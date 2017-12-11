#-------------------------------------------------
#
# Project created by QtCreator 2017-11-28T07:10:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LedMatrix
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    LedMatrix.cpp \
    LedDevice.cpp \
    Ws2811Device.cpp \
    GuiDevice.cpp \
    AnimatedValue.cpp \
    AnimatedPoint.cpp \
    Shape.cpp \
    Ball.cpp

HEADERS += \
        MainWindow.h \
    LedMatrix.h \
    LedDevice.h \
    Ws2811Device.h \
    GuiDevice.h \
    AnimatedValue.h \
    AnimatedPoint.h \
    Shape.h \
    Ball.h

FORMS += \
        MainWindow.ui

unix:!macx: LIBS += -L$$PWD/ws2811/ -lws2811

INCLUDEPATH += $$PWD/ws2811
DEPENDPATH += $$PWD/ws2811

unix:!macx: PRE_TARGETDEPS += $$PWD/ws2811/libws2811.a
