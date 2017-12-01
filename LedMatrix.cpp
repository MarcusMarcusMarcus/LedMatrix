#include "LedMatrix.h"


LedMatrix::LedMatrix(int width,int height) :
    m_image(width,height,QImage::Format_ARGB32)
{
}

const uint32_t *LedMatrix::pixel()
{
    const uchar *bits = m_image.bits();
    return reinterpret_cast<const uint32_t*>(bits);
}
