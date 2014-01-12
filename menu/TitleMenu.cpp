#define OPTIONS_COUNT 3

#include "../Font.h"
#include "../Color.h"
#include "../Game.h"
#include "../Sound.h"
#include "AboutMenu.h"
#include "InstructionsMenu.h"

#include "TitleMenu.h"

#include <sstream>

using namespace std;


TitleMenu::TitleMenu()
{
	options[0] = "Start game";
	options[1] = "How to play";
	options[2] = "About";
}

TitleMenu::~TitleMenu()
{
	// TODO Auto-generated destructor stub
}

void TitleMenu::tick()
{
	if (input->up->clicked) selected--;
	if (input->down->clicked) selected++;

	int len = OPTIONS_COUNT;
	if (selected < 0) selected += len;
	if (selected >= len) selected -= len;

	if (input->attack->clicked || input->menu->clicked) {
		if (selected == 0)
		{
			Sound::test->play();
			//game->resetGame();
			game->setMenu(NULL);
		}
		if (selected == 1) game->setMenu(new InstructionsMenu(this));
		if (selected == 2) game->setMenu(new AboutMenu(this));
	}
}

void TitleMenu::render(Screen * screen)
{
	screen->clear(0);

	int h = 2;
	int w = 13;
	int titleColor = Color::get(0, 010, 131, 551);
	int xo = (screen->w - w * 8) / 2;
	int yo = /*24*/8;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			screen->render(xo + x * 8, yo + y * 8, x + (y + 6) * 32, titleColor, 0);
		}
	}

	for (int i = 0; i < OPTIONS_COUNT; i++)
	{
		//string msg = TitleMenu::options[i];
		int col;
		stringstream msgStream;
		if (i == selected)
		{
			msgStream << "> " << options[i] << " <";
			col = Color::get(0, 555, 555, 555);
		}
		else
		{
			msgStream << options[i];
			col = Color::get(0, 222, 222, 222);
		}
		Font::draw(msgStream.str(), screen, (screen->w - msgStream.str().length() * 8) / 2, (5 + i) * 8, col);
	}

	Font::draw("Ported by Konchunas", screen, 0, screen->h - 8, Color::get(0, 111, 111, 111));
}
