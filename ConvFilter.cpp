#include "ConvFilter.h"
#include <limits>
#include <algorithm>

const stbi_uc COLOR_MIN = std::numeric_limits<stbi_uc>::min();
const stbi_uc COLOR_MAX = std::numeric_limits<stbi_uc>::max();


void ConvFilter::convolution(stbi_uc* point, const stbi_uc* locality, int comp)
{
    int temp = 0;
	const stbi_uc* iter;
	for (int k = 0; k < 3; k++)
	{
		temp = 0;
		for (int i = 0; i < size_; i++)
			for (int j = 0; j < size_; j++)
			{
				iter = (locality + (i * size_ + j) * comp);
				temp += mat(i, j) * iter[k];
			}
		temp /= norm;
		point[k] = temp;
	}
}

ConvFilter::ConvFilter(int t, int l, int b, int r, int size_, int norm_)
    : LocalityFilter(t, l, b, r, size_), norm(norm_)
{}

void ConvFilter::apply(png_toolkit& tool)
{
	image_data data = tool.getPixelData();
	int comp = data.compPerPixel;

	stbi_uc* temp = new stbi_uc[comp * size_ * size_];
	stbi_uc* buffer = new stbi_uc[comp * (b-t) * (r-l)];
	stbi_uc *begin_, *iter;
	begin_ = data.pixels;
	for (int i = t; i < b; i++)
	{
		begin_ = data.pixels + i * data.w * comp;
		for (int j = l; j < r; j++)
		{
			iter = begin_ + j * comp;
			formLocality(temp, tool, i, j);
			convolution(buffer + ((i-t) * (r-l) + (j-l)) * comp, temp, comp);
		}
	}

	for (int i = t; i < b; i++)
	{
		begin_ = data.pixels + i * data.w * comp;
		for (int j = l; j < r; j++)
		{
			iter = begin_ + j * comp;
			stbi_uc* pixel = buffer + ((i-t) * (r-l) + (j-l)) * comp;
			iter[0] = std::max<int>(COLOR_MIN, std::min<int>(pixel[0], COLOR_MAX));
			iter[1] = std::max<int>(COLOR_MIN, std::min<int>(pixel[1], COLOR_MAX));
			iter[2] = std::max<int>(COLOR_MIN, std::min<int>(pixel[2], COLOR_MAX));
		}
	}

	delete[] temp;
	delete[] buffer;
}
