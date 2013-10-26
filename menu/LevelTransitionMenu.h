#ifndef LEVELTRANSITIONMENU_H_
#define LEVELTRANSITIONMENU_H_

#include "Menu.h"

class LevelTransitionMenu : public Menu {
public:
	LevelTransitionMenu(int dir);
	virtual ~LevelTransitionMenu();

	void tick();
	void render(Screen * screen);

private:
	int dir;
	int time;
};

#endif /* LEVELTRANSITIONMENU_H_ */
