#pragma once
#include "myFilters.h"
#include <string>

AbstractFilter* getFilter(const std::string& name, int t, int l, int b, int r);
