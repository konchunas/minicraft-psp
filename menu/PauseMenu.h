#ifndef PAUSEMENU_H_
#define PAUSEMENU_H_

#include "Menu.h"
#include "../Screen.h"

#define OPTIONS_COUNT 2

class PauseMenu : public Menu {
public:
	PauseMenu();
	virtual ~PauseMenu();

	void tick();
	void render(Screen * screen);

private:
	int selected;
	string options[OPTIONS_COUNT];
};

#endif /* PAUSEMENU_H_ */
