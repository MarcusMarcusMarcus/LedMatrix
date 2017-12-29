# Raspberry C++/Qt5 code to run a LED matrix (WS2811)

## Building

```bash
scons
```

## Running

on the LED matrix, use `-d ws2811`
```bash
sudo ./Ball -platform linuxfb:fb=/dev/fb0 -d ws2811
```

on a framebuffer device (Raspberries without X installation)
```bash
./Ball -platform linuxfb:fb=/dev/fb0 -W 600 -H 400
```

In an X window
```
./Ball -W 600 -H 400
```
