#pragma once
#include "PointFilter.h"

class BlWhFilter : public PointFilter
{
private:
	void changePoint(stbi_uc* point) override;
public:
	BlWhFilter(int t, int l, int b, int r);
	~BlWhFilter() { };
};
