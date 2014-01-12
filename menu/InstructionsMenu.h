#ifndef INSTRUCTIONSMENU_H_
#define INSTRUCTIONSMENU_H_

#include "Menu.h"
#include "../Screen.h"

class InstructionsMenu : public Menu {
public:
	InstructionsMenu(Menu * parent);
	virtual ~InstructionsMenu();

	void tick();
	void render(Screen * screen);

private:
	Menu * parent;
};

#endif /* INSTRUCTIONSMENU_H_ */
