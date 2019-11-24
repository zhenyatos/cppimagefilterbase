#pragma once
#include "ConvFilter.h"

const int BLUR_SIZE = 3;

class BlurFilter : public ConvFilter
{
private:
	const int weights[BLUR_SIZE][BLUR_SIZE] =
	{
		{ 1, 1, 1},
		{ 1, 1, 1},
		{ 1, 1, 1}
	};
	const int norm = 9;
	void calc(stbi_uc* point, stbi_uc* locality, int comp) override;
public:
	BlurFilter(int t, int l, int b, int r);
	~BlurFilter() { };
};
