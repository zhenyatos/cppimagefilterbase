#include "PointFilter.h"

PointFilter::PointFilter(int t, int l, int b, int r)
	: AbstractFilter(t, l, b, r)
{}

void PointFilter::apply(png_toolkit& tool)
{
	image_data data = tool.getPixelData();
	stbi_uc *begin_, *iter;
	begin_ = data.pixels;
	for (int i = t; i < b; i++)
	{
		begin_ = data.pixels + i * data.w * data.compPerPixel;
		for (int j = l; j < r; j++)
		{
			iter = begin_ + j * data.compPerPixel;
			changePoint(iter);
		}
	}
}
