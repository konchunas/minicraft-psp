#ifndef TYPEABLE_H_
#define TYPEABLE_H_

enum Type
{
	UNDEFINED,
	MOB,
	PLAYER
};

class Typeable {
public:
	bool instanceOf(Type t)
	{
		if (this->type() == t)
			return true;
		return false;
	}

	virtual Type type()
	{
		return UNDEFINED;
	}
};

#endif /* TYPEABLE_H_ */
