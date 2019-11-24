#include <iostream>
#include <fstream>
#include "png_toolkit.h"
#include "myFilters.h"
#include "builder.h"

int main (int argc, char *argv[]) {
    try {
        if (argc != 4)
            throw "Not enough parameters";

		std::ifstream file;
		file.open(argv[1], std::ifstream::in);

		png_toolkit studTool;
		studTool.load(argv[2]);

		AbstractFilter* filter = nullptr;
		while (!file.eof())
		{
			std::string name;
			if(!(file >> name))
                break;

			int t, l, b, r;
			file >> t;
			file >> l;
			file >> b;
			file >> r;

			t = (t == 0) ? 0 : studTool.getPixelData().h / t;
			l = (l == 0) ? 0 : studTool.getPixelData().w / l;
			b = (b == 0) ? 0 : studTool.getPixelData().h / b;
			r = (r == 0) ? 0 : studTool.getPixelData().w / r;

			filter = getFilter(name, t, l, b, r);
			filter->apply(studTool);
			delete filter;
		}

        studTool.save(argv[3]);
		file.close();
    } catch (const char *str) {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
