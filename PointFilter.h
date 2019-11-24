#pragma once
#include "AbstractFilter.h"

class PointFilter : public AbstractFilter
{
private:
	virtual void changePoint(stbi_uc* point) = 0;
public:
	PointFilter(int t, int l, int b, int r);
	void apply(png_toolkit& tool) override;
    virtual ~PointFilter() { };
};
