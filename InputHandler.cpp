#include "InputHandler.h"
#include "InputHandler_Key.h"


InputHandler::InputHandler()
{
	init();
}

InputHandler::~InputHandler()
{

}

void InputHandler::init()
{
    up = new InputHandler_Key(this);
    down = new InputHandler_Key(this);
    left = new InputHandler_Key(this);
    right = new InputHandler_Key(this);
    attack = new InputHandler_Key(this);
    menu = new InputHandler_Key(this);
    exit = new InputHandler_Key(this);
    pause = new InputHandler_Key(this);
}

void InputHandler::releaseAll()
{
	for (uint i = 0; i < keys.size(); ++i)
	{
		keys.at(i)->down = false;
	}
}

void InputHandler::tick()
{
	for (uint i = 0; i < keys.size(); ++i)
	{
		keys.at(i)->tick();
	}
}

void InputHandler::handleKeys(OSL_CONTROLLER * keys)
{
	up->toggle(keys->held.up);
	down->toggle(keys->held.down);
	left->toggle(keys->held.left);
	right->toggle(keys->held.right);

	up->clicked = keys->pressed.up;
	down->clicked = keys->pressed.down;
	right->clicked = keys->pressed.right;
	left->clicked = keys->pressed.left;

	attack->clicked = keys->pressed.cross;
	menu->clicked = keys->pressed.square;
	exit->clicked = keys->pressed.circle;

	pause->clicked = keys->pressed.start;
}

void InputHandler::add(InputHandler_Key* key)
{
	keys.push_back(key);
}
