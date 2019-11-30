#pragma once
#include "ConvFilter.h"

const int BLUR_SIZE = 3;
const int BLUR_NORM = 9;

class BlurFilter : public ConvFilter
{
private:
    const int mat_[BLUR_SIZE][BLUR_SIZE] = {
        { 1, 1, 1 },
        { 1, 1, 1},
        { 1, 1, 1}
    };
    int mat(size_t i, size_t j) override;
public:
    BlurFilter(int t, int l, int b, int r);
    ~BlurFilter() { }
};
