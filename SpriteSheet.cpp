#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(OSL_IMAGE * image)
{
	width  = image->realSizeX; //image.getWidth();
	height = image->realSizeY; //image.getHeight();
	pixels = new int[ image->totalSize / sizeof(int) ];
	int * imageData = (int*)image->data;
	for (uint i = 0; i < image->totalSize / sizeof(int); i++)
	{
		pixels[i] = (imageData[i] & 0xFF) / 64;
		pixels[i] *= 8;
	}
	//oslDebug("about to delete image");
	//oslDeleteImage(image);
	//oslDebug("image deleted");
}

SpriteSheet::~SpriteSheet()
{
	//delete []pixels;
}

