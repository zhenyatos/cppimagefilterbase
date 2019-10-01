#include "filters.h"
const int RGBA_COMP = 4;
const int ALPHA_DEFAULT = 0xFF;

void recolorHalfImage(png_toolkit& studTool, stbi_uc R, stbi_uc G, stbi_uc B) {
	image_data data = studTool.getPixelData();
	stbi_uc* end = data.pixels + (data.h * data.w * data.compPerPixel);

	stbi_uc* iter = data.pixels + (data.h / 2) * data.w * data.compPerPixel;
	for (; iter < end; iter += data.compPerPixel) {
		iter[0] = R;
		iter[1] = G;
		iter[2] = B;
		if (data.compPerPixel == RGBA_COMP)
			iter[3] = ALPHA_DEFAULT;
	}
}