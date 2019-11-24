#include "BlurFilter.h"

void BlurFilter::calc(stbi_uc* point, stbi_uc* locality, int comp)
{
	int temp = 0;
	stbi_uc* iter;
	for (int k = 0; k < 3; k++)
	{
		temp = 0;
		for (int i = 0; i < size_; i++)
			for (int j = 0; j < size_; j++)
			{
				iter = locality + (i * size_ * comp) + j * comp;
				temp += weights[i][j] * iter[k];
			}
		temp /= norm;
		point[k] = temp;
	}
}

BlurFilter::BlurFilter(int t, int l, int b, int r)
	: ConvFilter(t, l, b, r, BLUR_SIZE)
{}
