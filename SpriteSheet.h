/*
 * SpriteSheet.h
 *
 *  Created on: 15 окт. 2013 г.
 *      Author: user
 */
#ifndef SPRITESHEET_H_
#define SPRITESHEET_H_

#include <oslib/oslib.h>

class SpriteSheet {
public:
	SpriteSheet(OSL_IMAGE * image);
	virtual ~SpriteSheet();
	int width, height;
	int *pixels;	//array

};

#endif /* SPRITESHEET_H_ */
