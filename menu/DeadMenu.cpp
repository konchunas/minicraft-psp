#include "../Font.h"
#include "../Color.h"
#include "../Game.h"
#include "../entity/Player.h"
#include "../Game.h"
#include "../item/Item.h"

#include "DeadMenu.h"

#include <sstream>

using namespace std;

DeadMenu::DeadMenu():
inputDelay(60)
{
	// TODO Auto-generated constructor stub
}

DeadMenu::~DeadMenu() {
	// TODO Auto-generated destructor stub
}

void DeadMenu::tick()
{
	if (inputDelay > 0)
		inputDelay--;
	else if (input->attack->clicked || input->menu->clicked)
	{
		//game->setMenu(new TitleMenu());
	}
}

void DeadMenu::render(Screen * screen)
{
	Font::renderFrame(screen, "", 1, 3, 18, 9);
	Font::draw("You died! Aww!", screen, 2 * 8, 4 * 8, Color::get(-1, 555, 555, 555));

	int seconds = game->gameTime / 60;
	int minutes = seconds / 60;
	int hours = minutes / 60;
	minutes %= 60;
	seconds %= 60;

	stringstream timeString;
	if (hours > 0) {
		timeString << hours << "h" << (minutes < 10 ? "0" : "") << minutes << "m";
	} else {
		timeString << minutes << "m " << (seconds < 10 ? "0" : "") << seconds << "s";
	}
	Font::draw("Time:", screen, 2 * 8, 5 * 8, Color::get(-1, 555, 555, 555));
	Font::draw(timeString.str(), screen, (2 + 5) * 8, 5 * 8, Color::get(-1, 550, 550, 550));
	Font::draw("Score:", screen, 2 * 8, 6 * 8, Color::get(-1, 555, 555, 555));
	stringstream ss;
	ss << game->player->score;
	Font::draw(ss.str(), screen, (2 + 6) * 8, 6 * 8, Color::get(-1, 550, 550, 550));
	Font::draw("Press X to lose", screen, 2 * 8, 8 * 8, Color::get(-1, 333, 333, 333));
}
