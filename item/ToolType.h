#ifndef TOOLTYPE_H_
#define TOOLTYPE_H_

#include <string>

using namespace std;

class ToolType {
public:
	ToolType(string name, int sprite);
	virtual ~ToolType();
	static ToolType* shovel;
	static ToolType* hoe;
	static ToolType* sword;
	static ToolType* pickaxe;
	static ToolType* axe;

	string name;
	int sprite;
};

#endif /* TOOLTYPE_H_ */
