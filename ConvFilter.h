#pragma once
#include "AbstractFilter.h"

class ConvFilter : public AbstractFilter
{
protected:
	int size_;
private:
	void formLocality(stbi_uc* locality, const png_toolkit& tool, int k, int l);
	virtual void calc(stbi_uc* point, stbi_uc* locality, int comp) = 0;
public:
	ConvFilter(int t, int l, int b, int r, int size_);
	virtual void apply(png_toolkit& tool) override;
	virtual ~ConvFilter() { };
};
