#ifndef GAME_H_
#define GAME_H_

#include <oslib/oslib.h>

#include "Screen.h"
#include "InputHandler.h"
#include "entity/Player.h"
#include "level/Level.h"

class Menu;

class Game {
public:
	Game();
	virtual ~Game();
	void run();
	void init();
	void render();
	void tick();
	void setMenu(Menu*);
	void scheduleLevelChange(int dir);
	void changeLevel(int dir);

	bool running;

private:
	OSL_IMAGE * image;
	OSL_IMAGE * renderImage;
	OSL_IMAGE * spriteSheet; //class member only for debug needs
//	int xScroll;//class member only for debug needs
//	int yScroll;//class member only for debug needs
	Screen * screen;
	Screen * lightScreen;
	InputHandler * input;
	Level * level;
	Player * player;
	Menu * menu;
	//Level[] levels = new Level[5];
	int * colors;
	int * pixels;
	int currentLevel;
	Level ** levels;
	int pendingLevelChange;
	int playerDeadTime;


	void renderGui();
};

#endif /* GAME_H_ */
