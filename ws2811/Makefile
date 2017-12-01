HEADERS = clk.h  dma.h pcm.h pwm.h rpihw.h \
          gpio.h mailbox.h version.h ws2811.h
SOURCES = dma.c mailbox.c pcm.c pwm.c rpihw.c ws2811.c

OBJECTS=$(SOURCES:.c=.o)

all: $(OBJECTS)
	ar rcs libws2811.a $(OBJECTS)

%.o: %.c
	gcc -O3 $(CXXFLAGS) -c $< -o $@
