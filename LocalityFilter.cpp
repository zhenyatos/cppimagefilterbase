#include "LocalityFilter.h"

void LocalityFilter::formLocality(stbi_uc* locality, const png_toolkit& tool, int n, int m)
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
					pos[k] = outOfBorders;
			else
				for (int k = 0; k < comp; k++)
					pos[k] = ((data.pixels + I * data.w * comp) + J * comp)[k];
		}
}

LocalityFilter::LocalityFilter(int t, int l, int b, int r, int size_)
	: AbstractFilter(t, l, b, r), size_(size_)
{}
