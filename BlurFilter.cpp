#include "BlurFilter.h"

int BlurFilter::mat(size_t i, size_t j)
{
    return mat_[i][j];
}

BlurFilter::BlurFilter(int t, int l, int b, int r)
    : ConvFilter(t, l, b, r, BLUR_SIZE, BLUR_NORM)
{}
