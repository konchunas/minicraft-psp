#ifndef WONMENU_H_
#define WONMENU_H_

#include "Menu.h"
#include "../Screen.h"

class WonMenu : public Menu {
public:
	WonMenu();
	virtual ~WonMenu();

	void tick();
	void render(Screen * screen);

private:
	int inputDelay;
};

#endif /* WONMENU_H_ */
