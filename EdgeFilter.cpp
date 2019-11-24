#include <algorithm>
#include "EdgeFilter.h"

void EdgeFilter::calc(stbi_uc* point, stbi_uc* locality, int comp)
{
	int temp = 0;
	stbi_uc* iter;
    temp = 0;
    for (int i = 0; i < size_; i++)
        for (int j = 0; j < size_; j++)
        {
            iter = locality + (i * size_ * comp) + j * comp;
            temp += weights[i][j] * iter[0];
        }
    temp /= norm;
    temp = std::min<int>(0xFF, std::max<int>(temp, 0x00));
    point[0] = temp;
    point[1] = temp;
    point[2] = temp;
}

EdgeFilter::EdgeFilter(int t, int l, int b, int r)
	: ConvFilter(t, l, b, r, EDGE_SIZE)
{}

void EdgeFilter::apply(png_toolkit& tool)
{
    BlWhFilter prefilter(t, l, b, r);
    prefilter.apply(tool);
    ConvFilter::apply(tool);
}
