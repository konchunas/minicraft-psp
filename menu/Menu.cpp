#include "Menu.h"

#include "../Game.h"
#include "../InputHandler.h"
#include "../Color.h"
#include "../Font.h"

void Menu::init(Game * game, InputHandler * input)
{
	this->input = input;
	this->game = game;
}

void Menu::tick()
{
}

void Menu::render(Screen * screen)
{
	oslDebug("hey, whata you doing here?");
}

void Menu::renderItemList(Screen * screen, int xo, int yo, int x1, int y1, deque<Item*> &listItems, int selected)
{
	bool renderCursor = true;
	if (selected < 0)
	{
		selected = -selected - 1;
		renderCursor = false;
	}
	int w = x1 - xo;
	int h = y1 - yo - 1;
	int i0 = 0;
	int i1 = listItems.size();
	if (i1 > h) i1 = h;
	int io = selected - int(h / 2);

	//this piece of code does not work in java copypaste
	//so I had to create separate variable to workaround this
	//java: if (io > listItems.size() - h) io = listItems.size() - h;
	int heightDiff = listItems.size() - h;
	if (io > heightDiff) io = heightDiff;

	if (io < 0) io = 0;

	for (int i = i0; i < i1; i++)
	{
		listItems.at(i + io)->renderInventory(screen, (1 + xo) * 8, (i + 1 + yo) * 8);
	}
	if (renderCursor)
	{
		int yy = selected + 1 - io + yo;
		Font::draw(">", screen, (xo + 0) * 8, yy * 8, Color::get(5, 555, 555, 555));
		Font::draw("<", screen, (xo + w) * 8, yy * 8, Color::get(5, 555, 555, 555));
	}
}

void Menu::renderItemList(Screen * screen, int xo, int yo, int x1, int y1, deque<Recipe*> &listItems, int selected)
{
	bool renderCursor = true;
	if (selected < 0)
	{
		selected = -selected - 1;
		renderCursor = false;
	}
	int w = x1 - xo;
	int h = y1 - yo - 1;
	int i0 = 0;
	int i1 = listItems.size();
	if (i1 > h) i1 = h;
	int io = selected - int(h / 2);

	//this piece of code does not work in java copypaste
	//so I had to create separate variable to workaround this
	//java: if (io > listItems.size() - h) io = listItems.size() - h;
	int heightDiff = listItems.size() - h;
	if (io > heightDiff) io = heightDiff;

	if (io < 0) io = 0;

	for (int i = i0; i < i1; i++)
	{
		listItems.at(i + io)->renderInventory(screen, (1 + xo) * 8, (i + 1 + yo) * 8);
	}
	if (renderCursor)
	{
		int yy = selected + 1 - io + yo;
		Font::draw(">", screen, (xo + 0) * 8, yy * 8, Color::get(5, 555, 555, 555));
		Font::draw("<", screen, (xo + w) * 8, yy * 8, Color::get(5, 555, 555, 555));
	}
}
