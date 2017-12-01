#pragma once
#include <cinttypes>
#include <QImage>

class LedMatrix
{
public:
    LedMatrix(int width, int height);

    int width() { return m_image.width(); }
    int height() { return m_image.height(); }
    const uint32_t *pixel();
    QImage &image() { return m_image; }

private:

    QImage m_image;
};
