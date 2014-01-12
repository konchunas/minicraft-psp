#include "../Font.h"
#include "../Color.h"
#include "../Game.h"

#include "InstructionsMenu.h"

#include <sstream>

using namespace std;

InstructionsMenu::InstructionsMenu(Menu * parent)
{
	this->parent = parent;
}

InstructionsMenu::~InstructionsMenu()
{
	// TODO Auto-generated destructor stub
}

void InstructionsMenu::tick()
{
	if (input->attack->clicked || input->menu->clicked || input->exit->clicked)
	{
		game->setMenu(parent);
	}
}

void InstructionsMenu::render(Screen * screen)
{
	screen->clear(0);

	Font::draw("HOW TO PLAY", screen, 4 * 8 + 4, 0, Color::get(0, 555, 555, 555));
	Font::draw("X - attack", screen, 0 * 8 + 4, 1 * 8, Color::get(0, 333, 333, 333));
	Font::draw("Square - inventory", screen, 0 * 8 + 4, 2 * 8, Color::get(0, 333, 333, 333));
	Font::draw("Select an item in", screen, 0 * 8 + 4, 3 * 8, Color::get(0, 333, 333, 333));
	Font::draw("the inventory to", screen, 0 * 8 + 4, 4 * 8, Color::get(0, 333, 333, 333));
	Font::draw("equip it.", screen, 0 * 8 + 4, 5 * 8, Color::get(0, 333, 333, 333));
	Font::draw("To select nothing", screen, 0 * 8 + 4, 6 * 8, Color::get(0, 333, 333, 333));
	Font::draw("just enter and", screen, 0 * 8 + 4, 7 * 8, Color::get(0, 333, 333, 333));
	Font::draw("exit the invertory.", screen, 0 * 8 + 4, 8 * 8, Color::get(0, 333, 333, 333));
	Font::draw("Kill the air wizard", screen, 0 * 8 + 4, 9 * 8, Color::get(0, 333, 333, 333));
	Font::draw("to win the game!", screen, 0 * 8 + 4, 10 * 8, Color::get(0, 333, 333, 333));
}

