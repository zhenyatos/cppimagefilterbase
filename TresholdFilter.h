#pragma once
#include "LocalityFilter.h"

const int TRESHOLD_SIZE = 5;

class TresholdFilter : public LocalityFilter
{
private:
    bool lessThanMedian(const stbi_uc* point, int i, int j, stbi_uc* locality, int comp);
public:
    TresholdFilter(int t, int l, int b, int r);
    void apply(png_toolkit& tool) final;
    ~TresholdFilter() { };
};

