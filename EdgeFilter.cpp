#include "EdgeFilter.h"
#include "BlWhFilter.h"

int EdgeFilter::mat(size_t i, size_t j)
{
    return mat_[i][j];
}

EdgeFilter::EdgeFilter(int t, int l, int b, int r)
    : ConvFilter(t, l, b, r, EDGE_SIZE, EDGE_NORM)
{}

void EdgeFilter::apply(png_toolkit& tool)
{
    BlWhFilter preFilter(t, l, b, r);
    preFilter.apply(tool);
    ConvFilter::apply(tool);
}
