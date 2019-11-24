#pragma once
#include "PointFilter.h"

class RedFilter : public PointFilter
{
private:
	void changePoint(stbi_uc* point) override;
public:
	RedFilter(int t, int l, int b, int r);
	~RedFilter() { };
};
