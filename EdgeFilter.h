#pragma once
#include "ConvFilter.h"

const int EDGE_SIZE = 3;
const int EDGE_NORM = 1;

class EdgeFilter : public ConvFilter
{
private:
    const int mat_[EDGE_SIZE][EDGE_SIZE] = {
        { -1, -1, -1 },
        { -1, 9, -1},
        { -1, -1, -1}
    };
    int mat(size_t i, size_t j) override;
public:
    EdgeFilter(int t, int l, int b, int r);
    void apply(png_toolkit& tool) final;
    ~EdgeFilter() { }
};
