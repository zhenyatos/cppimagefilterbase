#pragma once
#include "ConvFilter.h"
#include "BlWhFilter.h"

const int EDGE_SIZE = 3;

class EdgeFilter : public ConvFilter
{
private:
	const int weights[EDGE_SIZE][EDGE_SIZE] =
	{
		{ -1, -1, -1},
		{ -1, 9, -1},
		{ -1, -1, -1}
	};
	const int norm = 1;
	void calc(stbi_uc* point, stbi_uc* locality, int comp) override;
public:
	EdgeFilter(int t, int l, int b, int r);
	void apply(png_toolkit& tool) override;
	~EdgeFilter() { };
};
