#ifndef DEADMENU_H_
#define DEADMENU_H_

#include "Menu.h"
#include "../Screen.h"

class DeadMenu : public Menu {
public:
	DeadMenu();
	virtual ~DeadMenu();

	void tick();
	void render(Screen * screen);

private:
	int inputDelay;
};

#endif /* DEADMENU_H_ */
