// Generated from /minicraft/src/com/mojang/ld22/InputHandler.java
#ifndef INPUT_HANDLER_KEY_H_
#define INPUT_HANDLER_KEY_H_

class InputHandler;

class InputHandler_Key
{
public:
	InputHandler_Key(InputHandler* inputHandler);
	~InputHandler_Key();
    int presses, absorbs;
    bool down, clicked;

    void toggle(bool pressed);
    void tick();

private:
    friend class InputHandler;
};

#endif
