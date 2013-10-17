#ifndef FONT_H_
#define FONT_H_

#include <string>
#include "Screen.h"

using namespace std;

class Font {
public:
	Font();
	virtual ~Font();

	static void draw(string msg, Screen * screen, int x, int y, int col);
	static void renderFrame(Screen * screen, string title, int x0, int y0, int x1, int y1);

private:
	static string chars;
};

#endif /* FONT_H_ */
