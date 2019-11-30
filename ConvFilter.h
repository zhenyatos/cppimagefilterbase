#pragma once
#include "LocalityFilter.h"

class ConvFilter : public LocalityFilter
{
private:
    void convolution(stbi_uc* point, const stbi_uc* locality, int comp);
    virtual int mat(size_t i, size_t j) = 0;
    const int norm;
public:
    ConvFilter(int t, int l, int b, int r, int size_, int norm_);
    virtual void apply(png_toolkit& tool) override;
    virtual ~ConvFilter() { };
};
