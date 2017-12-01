HEADERS = LedMatrix.h MainWindow.h
UI_FILES = MainWindow.ui
MOC_HEADERS = MainWindow.h
SOURCES = LedMatrix.cpp MainWindow.cpp main.cpp \
          GuiDevice.cpp LedDevice.cpp Ws2811Device.cpp \
          AnimatedValue.cpp

LIBS = -Lws2811 -lws2811 \
       -L/usr/lib/arm-linux-gnueabihf \
       -lQt5Core \
       -lQt5Widgets \
       -lQt5Gui
QTINC = /usr/include/arm-linux-gnueabihf/qt5
INCDIRS = -I. \
          -Iws2811 \
          -I$(QTINC) \
          -I$(QTINC)/QtWidgets \
          -I$(QTINC)/QtGui \
          -I$(QTINC)/QtCore
CXXFLAGS = -O3 -std=c++1z

EXECUTABLE = ledMatrix

MOC_SOURCES=$(MOC_HEADERS:.h=.moc.cpp)
UIC_HEADERS=$(addprefix ui_,$(UI_FILES:.ui=.h))
OBJECTS=$(SOURCES:.cpp=.o) $(MOC_SOURCES:.cpp=.o)

all: $(UIC_HEADERS) $(EXECUTABLE) 
	@echo Done!

$(EXECUTABLE): $(OBJECTS)
	g++ $^ $(LIBS) -o $@

%.o: %.cpp
	g++ $(CXXFLAGS) $(INCDIRS) -c $< -o $@

%.moc.cpp: %.h
	moc $(INCDIRS) $< -o $@

ui_%.h: %.ui
	uic $< -o $@

clean:
	rm -f ui*.h moc_*.cpp *.o ledMatrix
