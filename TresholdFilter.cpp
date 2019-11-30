#include "TresholdFilter.h"
#include "BlWhFilter.h"
#include <vector>
#include <algorithm>

bool ThresholdFilter::lessThanMedian(const stbi_uc* point, int I, int J, stbi_uc* locality, int comp)
{
    std::vector<stbi_uc> vec;
    int counter = 0;
    for (int i = 0; i < size_; i++)
        for (int j = 0; j < size_; j++)
        {
            int relX = I - (size_ / 2) + i;
            int relY = J - (size_ / 2) + j;
            if (relX < t || relX >= b || relY < l || relY >= r)
                continue;
            vec.push_back((locality + (i * size_ + j) * comp)[0]);
            counter++;
        }
    std::sort(vec.begin(), vec.end());
    if (point[0] < vec[counter / 2])
        return true;
    return false;
}

ThresholdFilter::ThresholdFilter(int t, int l, int b, int r)
    : LocalityFilter(t, l, b, r, TRESHOLD_SIZE)
{}

void ThresholdFilter::apply(png_toolkit& tool)
{
    BlWhFilter preFilter(t, l, b, r);
    preFilter.apply(tool);

    image_data data = tool.getPixelData();
    int comp = data.compPerPixel;
    stbi_uc* temp = new stbi_uc[comp * size_ * size_];
	stbi_uc *begin_, *iter;
	begin_ = data.pixels;
	for (int i = t; i < b; i++)
	{
		begin_ = data.pixels + i * data.w * comp;
		for (int j = l; j < r; j++)
		{
			iter = begin_ + j * comp;
			formLocality(temp, tool, i, j);
			if (lessThanMedian(iter, i, j, temp, comp))
                iter[0] = iter[1] = iter[2] = 0;
		}
	}

	delete[] temp;
}
