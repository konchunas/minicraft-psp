// Generated from /minicraft/src/com/mojang/ld22/InputHandler.java
#ifndef INPUT_HANDLER_H_
#define INPUT_HANDLER_H_

#include <oslib/oslib.h>
#include <vector>

#include "InputHandler_Key.h"
#include "Game.h"

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
    std::vector<InputHandler_Key*> keys;
    InputHandler_Key* up;
    InputHandler_Key* down;
    InputHandler_Key* left;
    InputHandler_Key* right;
    InputHandler_Key* attack;
    InputHandler_Key* menu;
    void releaseAll();
    void tick();
    void add(InputHandler_Key*);
    void handleKeys(OSL_CONTROLLER*);

private:
    void init();


public:
    friend class InputHandler_Key;
};

#endif
