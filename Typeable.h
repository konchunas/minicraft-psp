#ifndef TYPEABLE_H_
#define TYPEABLE_H_

enum ClassType
{
	UNDEFINED,
	MOB,
	PLAYER,
	TOOL_ITEM,
	RESOURCE_ITEM
};

//this class is intended to replace java instainceOf function using predefined enums

class Typeable {
public:
	bool instanceOf(ClassType t)
	{
		if (this->classType() == t)
			return true;
		return false;
	}

	virtual ClassType classType()
	{
		return UNDEFINED;
	}
};

#endif /* TYPEABLE_H_ */
