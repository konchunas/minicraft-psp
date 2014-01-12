#include "../Font.h"
#include "../Color.h"
#include "../Game.h"
#include "../entity/Player.h"
#include "../Game.h"
#include "../item/Item.h"

#include "WonMenu.h"

#include <sstream>

using namespace std;

WonMenu::WonMenu():
inputDelay(60)
{

}

WonMenu::~WonMenu() {
	// TODO Auto-generated destructor stub
}

void WonMenu::tick()
{
	if (inputDelay > 0)
		inputDelay--;
	else if (input->attack->clicked || input->menu->clicked || input->exit->clicked)
	{
		//game->setMenu(new TitleMenu());
	}
}

void WonMenu::render(Screen * screen)
{
	Font::renderFrame(screen, "", 1, 3, 18, 9);
	Font::draw("You won! Yay!", screen, 2 * 8, 4 * 8, Color::get(-1, 555, 555, 555));

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
	Font::draw("Press X to win", screen, 2 * 8, 8 * 8, Color::get(-1, 333, 333, 333));
}
