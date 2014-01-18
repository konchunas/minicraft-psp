#include "../Font.h"
#include "../Color.h"
#include "../Game.h"
#include "ExitConfirmationMenu.h"

#include "PauseMenu.h"

#include <sstream>

using namespace std;

PauseMenu::PauseMenu():
selected(0)
{
	options[0] = "Resume";
	options[1] = "Quit";
}

PauseMenu::~PauseMenu()
{

}

void PauseMenu::tick()
{
	if (input->up->clicked) selected--;
	if (input->down->clicked) selected++;

	int len = OPTIONS_COUNT;
	if (selected < 0) selected += len;
	if (selected >= len) selected -= len;

	if (input->attack->clicked)
	{
		if (selected == 0) game->setMenu(NULL);
		if (selected == 1) game->setMenu(new ExitConfirmationMenu(this));
	}

	if (input->exit->clicked || input->pause->clicked)
	{
		game->setMenu(NULL);
	}
}

void PauseMenu::render(Screen * screen)
{
	int menuWidth = 12;
	int yo = 2;
	int xo = 1;
	Font::renderFrame(screen, "pause", xo, yo - 1, menuWidth, 4);
	for (int i = 0; i < OPTIONS_COUNT; i++)
	{
		Font::draw(options[i], screen, (xo + 1) * 8, (2 + i) * 8, Color::get(-1, 555, 555, 555));
	}
	int yy = selected + yo;
	Font::draw(">", screen, (xo ) * 8, yy * 8, Color::get(5, 555, 555, 555));
	Font::draw("<", screen, (xo + menuWidth - 1) * 8, yy * 8, Color::get(5, 555, 555, 555));
}
