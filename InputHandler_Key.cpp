// Generated from /minicraft/src/com/mojang/ld22/InputHandler.java

#include "InputHandler_Key.h"

#include "InputHandler.h"

#include <oslib/oslib.h>

InputHandler_Key::InputHandler_Key(InputHandler * inputHandler):
absorbs(0),
presses(0),
down(false),
clicked(false)
{
	inputHandler->add(this);
}

InputHandler_Key::~InputHandler_Key()
{

}

void InputHandler_Key::toggle(bool pressed)
{
    if(pressed != down)
    {
        down = pressed;
    }
    if(pressed)
    {
        presses++;
    }
}

void InputHandler_Key::tick()
{
//    if(absorbs < presses) {
//        absorbs++;
//        clicked = true;
//    } else {
//        clicked = false;
//    }
	if (clicked)
	{
		clicked = false;
	}
}



