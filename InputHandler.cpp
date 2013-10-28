// Generated from /minicraft/src/com/mojang/ld22/InputHandler.java
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

		//if (keys->pressed.cross);
		attack->clicked = keys->pressed.cross;
		menu->clicked = keys->pressed.square;

		//menu->toggle(keys->held.start);
		//menu->toggle(keys->held.square);

//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_NUMPAD8)
//        npc(up)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_NUMPAD2)
//        npc(down)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_NUMPAD4)
//        npc(left)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_NUMPAD6)
//        npc(right)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_W)
//        npc(up)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_S)
//        npc(down)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_A)
//        npc(left)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_D)
//        npc(right)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_UP)
//        npc(up)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_DOWN)
//        npc(down)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_LEFT)
//        npc(left)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_RIGHT)
//        npc(right)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_TAB)
//        npc(menu)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_ALT)
//        npc(menu)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_ALT_GRAPH)
//        npc(menu)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_SPACE)
//        npc(attack)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_CONTROL)
//        npc(attack)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_NUMPAD0)
//        npc(attack)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_INSERT)
//        npc(attack)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_ENTER)
//        npc(menu)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_X)
//        npc(menu)->toggle(pressed);
//
//    if(npc(ke)->getKeyCode() == ::java::awt::event::KeyEvent::VK_C)
//        npc(attack)->toggle(pressed);

}

void InputHandler::add(InputHandler_Key* key)
{
	keys.push_back(key);
}
