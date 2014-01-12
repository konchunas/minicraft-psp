#ifndef TITLEMENU_H_
#define TITLEMENU_H_

#include "Menu.h"
#include "../Screen.h"

#include <string>

class TitleMenu : public Menu {
public:
	TitleMenu();
	virtual ~TitleMenu();

	void tick();
	void render(Screen * screen);

private:
	int selected;
	string options[3];
};

#endif /* TITLEMENU_H_ */
