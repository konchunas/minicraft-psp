#include <sstream>

#include "../Color.h"
#include "../Font.h"

#include "TextParticle.h"

TextParticle::~TextParticle() {
	// TODO Auto-generated destructor stub
}

TextParticle::TextParticle(string msg, int x, int y, int col)
{
	init(msg, x, y, col);
}

TextParticle::TextParticle(int num, int x, int y, int col)
{
	stringstream msgStream;
	msgStream << num;
	init(msgStream.str(), x, y, col);
}

void TextParticle::init(string msg, int x, int y, int col)
{
	this->msg = msg;
	this->x = x;
	this->y = y;
	this->col = col;
	time = 0;
	xx = x;
	yy = y;
	zz = 2;
	xa = random->nextGaussian() * 0.3;
	ya = random->nextGaussian() * 0.2;
	za = random->nextFloat() * 0.7 + 2;
}

void TextParticle::tick()
{
	time++;
	if (time > 60) {
		remove();
	}
	xx += xa;
	yy += ya;
	zz += za;
	if (zz < 0) {
		zz = 0;
		za *= -0.5;
		xa *= 0.6;
		ya *= 0.6;
	}
	za -= 0.15;
	x = (int) xx;
	y = (int) yy;
}

void TextParticle::render(Screen * screen)
{
	Font::draw(msg, screen, x - msg.length() * 4 + 1, y - (int) (zz) + 1, Color::get(-1, 0, 0, 0));
	Font::draw(msg, screen, x - msg.length() * 4, y - (int) (zz), col);
}
