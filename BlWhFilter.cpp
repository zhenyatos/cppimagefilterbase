#include "BlWhFilter.h"

void BlWhFilter::changePoint(stbi_uc* point)
{
	int val = (3 * point[0] + 6 * point[1] + point[2]) / 10;
	point[0] = point[1] = point[2] = val;
}

BlWhFilter::BlWhFilter(int t, int l, int b, int r)
	: PointFilter(t, l, b, r)
{}
