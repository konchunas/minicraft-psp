/*
 * Screen.h
 *
 *  Created on: 16 окт. 2013 г.
 *      Author: user
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SpriteSheet.h>

class Screen {
public:
	Screen(int w, int h, SpriteSheet * sheet);
	virtual ~Screen();
	int xOffset;
	int yOffset;

	static const int BIT_MIRROR_X = 0x01;
	static const int BIT_MIRROR_Y = 0x02;

	int w, h;
	ushort * pixels;

	void clear(int);
	void renderLight(int x, int y, int r);
	void overlay(Screen * screen, int xa, int ya);
	void setOffset(int xOffset, int yOffset);
	void render(int xp, int yp, int tile, int colors, int bits);
	void render2(int xp, int yp, int tile, int colors, int bits);

private:
	SpriteSheet * sheet;
	int * dither;
};

#endif /* SCREEN_H_ */
