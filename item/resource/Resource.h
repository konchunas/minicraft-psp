#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <string>

class Tile;
class Level;
class Player;

using namespace std;

class Resource {
public:

	Resource(string name, int sprite, int color);
	virtual ~Resource();

	static Resource * wood;
	static Resource * stone;
	static Resource * flower;
	static Resource * acorn;
	static Resource * dirt;
	static Resource * sand;
	static Resource * cactusFlower;
	static Resource * seeds;
	static Resource * wheat;
	static Resource * bread;
	static Resource * apple;

	static Resource * coal;
	static Resource * ironOre;
	static Resource * goldOre;
	static Resource * ironIngot;
	static Resource * goldIngot;

	static Resource * slime;
	static Resource * glass;
	static Resource * cloth;
	static Resource * cloud;
	static Resource * gem;

	string name;
	int sprite;
	int color;

	static void init();
	virtual bool interactOn(Tile * tile, Level * level, int xt, int yt, Player * player, int attackDir);
};

#endif /* RESOURCE_H_ */
