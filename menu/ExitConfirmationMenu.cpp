#include "../Font.h"
#include "../Color.h"
#include "../Game.h"
#include "TitleMenu.h"
#include "ExitConfirmationMenu.h"

#include <sstream>

using namespace std;

ExitConfirmationMenu::ExitConfirmationMenu(Menu * parent):
selected(0),
parent(parent)
{
	options[0] = "No";
	options[1] = "Yes";
}

ExitConfirmationMenu::~ExitConfirmationMenu()
{

}

void ExitConfirmationMenu::tick()
{
	if (input->up->clicked) selected--;
	if (input->down->clicked) selected++;

	int len = OPTIONS_COUNT;
	if (selected < 0) selected += len;
	if (selected >= len) selected -= len;

	if (input->attack->clicked)
	{
		if (selected == 0) game->setMenu(parent);
		if (selected == 1) game->setMenu(new TitleMenu());
	}

	if (input->exit->clicked)
	{
		game->setMenu(parent);
	}
}

void ExitConfirmationMenu::render(Screen * screen)
{
	int menuWidth = 12;
	int yo = 2;
	int xo = 1;
	Font::renderFrame(screen, "quit?", xo, yo - 1, menuWidth, 4);
	for (int i = 0; i < OPTIONS_COUNT; i++)
	{
		Font::draw(options[i], screen, (xo + 1) * 8, (2 + i) * 8, Color::get(-1, 555, 555, 555));
	}
	int yy = selected + yo;
	Font::draw(">", screen, (xo ) * 8, yy * 8, Color::get(5, 555, 555, 555));
	Font::draw("<", screen, (xo + menuWidth - 1) * 8, yy * 8, Color::get(5, 555, 555, 555));
}
