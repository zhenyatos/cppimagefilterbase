#include "RedFilter.h"

void RedFilter::changePoint(stbi_uc* point)
{
	point[0] = 0xFF;
	point[1] = 0x00;
	point[2] = 0x00;
}

RedFilter::RedFilter(int t, int l, int b, int r)
	: PointFilter(t, l, b, r)
{}
