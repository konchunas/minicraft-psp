#ifndef EXITCONFIRMATIONMENU_H_
#define EXITCONFIRMATIONMENU_H_

#include "Menu.h"
#include "../Screen.h"

#define OPTIONS_COUNT 2

class ExitConfirmationMenu : public Menu {
public:
	ExitConfirmationMenu(Menu * parent);
	virtual ~ExitConfirmationMenu();

	void tick();
	void render(Screen * screen);

private:
	int selected;
	string options[OPTIONS_COUNT];
	Menu * parent;
};

#endif /* EXITCONFIRMATIONMENU_H_ */
