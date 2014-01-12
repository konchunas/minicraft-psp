#ifndef ABOUTMENU_H_
#define ABOUTMENU_H_

#include "Menu.h"
#include "../Screen.h"

class AboutMenu : public Menu {
public:
	AboutMenu(Menu * parent);
	virtual ~AboutMenu();

	void tick();
	void render(Screen * screen);

private:
	Menu * parent;
};

#endif /* ABOUTMENU_H_ */
