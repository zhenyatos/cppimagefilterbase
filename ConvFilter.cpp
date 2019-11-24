#include "ConvFilter.h"

void ConvFilter::formLocality(stbi_uc* locality, const png_toolkit& tool, int n, int m)
{
	image_data data = tool.getPixelData();
	int comp = data.compPerPixel;
	stbi_uc *pos;
	for (int i = 0; i < size_; i++)
		for (int j = 0; j < size_; j++)
		{
			int I = n - (size_ / 2) + i;
			int J = m - (size_ / 2) + j;
			pos = (locality + i * size_ * comp) + j * comp;
			if (I < t || I >= b || J < l || J >= r)
				for (int k = 0; k < comp; k++)
					pos[k] = 0;
			else
				for (int k = 0; k < comp; k++)
					pos[k] = ((data.pixels + I * data.w * comp) + J * comp)[k];
		}
}

ConvFilter::ConvFilter(int t, int l, int b, int r, int size_)
	: AbstractFilter(t, l, b, r), size_(size_)
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
			calc(buffer + ((i-t) * (r-l) + (j-l)) * comp, temp, comp);
		}
	}

	for (int i = t; i < b; i++)
	{
		begin_ = data.pixels + i * data.w * comp;
		for (int j = l; j < r; j++)
		{
			iter = begin_ + j * comp;
			stbi_uc* pixel = buffer + ((i-t) * (r-l) + (j-l)) * comp;
			iter[0] = pixel[0];
			iter[1] = pixel[1];
			iter[2] = pixel[2];
		}
	}


	delete[] temp;
	delete[] buffer;
}
