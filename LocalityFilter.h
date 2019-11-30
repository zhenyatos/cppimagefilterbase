#pragma once
#include "AbstractFilter.h"

class LocalityFilter : public AbstractFilter
{
protected:
	const int size_;
	const int outOfBorders = 0;
	void formLocality(stbi_uc* locality, const png_toolkit& tool, int k, int l);
public:
	LocalityFilter(int t, int l, int b, int r, int size_);
	virtual ~LocalityFilter() { };
};
