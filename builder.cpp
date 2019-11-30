#include "builder.h"

enum filterName { UNDEFINED, RED, BLUR, EDGE, TRESHOLD };
const std::string RED_NAME = "Red";
const std::string BLUR_NAME = "Blur";
const std::string EDGE_NAME = "Edge";
const std::string TRESHOLD_NAME = "Treshold";

filterName strToCode(const std::string& name)
{
	if (name == RED_NAME)
		return RED;
	if (name == BLUR_NAME)
		return BLUR;
	if (name == EDGE_NAME)
		return EDGE;
    if (name == TRESHOLD_NAME)
        return TRESHOLD;
	return UNDEFINED;
}

AbstractFilter* getFilter(const std::string& name, int t, int l, int b, int r)
{
	filterName filterCode = strToCode(name);

	switch (filterCode)
	{
	case RED:
		return new RedFilter(t, l, b, r);
	case BLUR:
		return new BlurFilter(t, l, b, r);
	case EDGE:
		return new EdgeFilter(t, l, b, r);
    case TRESHOLD:
        return new TresholdFilter(t, l, b, r);
    case UNDEFINED:
        return nullptr;
	}

	return nullptr;
}
