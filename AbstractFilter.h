#pragma once
#include "png_toolkit.h"

class AbstractFilter
{
protected:
	int t;
	int l;
	int b;
	int r;
public:
	AbstractFilter(int t, int l, int b, int r);
	virtual void apply(png_toolkit& tool) = 0;
	virtual ~AbstractFilter() { };
};
