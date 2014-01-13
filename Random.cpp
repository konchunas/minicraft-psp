//#include <psprtc.h>

#include "Random.h"

#include <stdlib.h>
#include <time.h>
#include <oslib/oslmath.h>

Random::Random()
{
	oslSrand(time(0));
}

Random::~Random()
{
	// TODO Auto-generated destructor stub
}

int Random::nextInt(int upper)
{
	return (int)oslRandf(0, upper);
}

float Random::nextFloat()
{
	return oslRandf(0, (float)0.99999999999);
}

double Random::nextGaussian()
{
	return nextFloat();
}

bool Random::nextBoolean()
{
	return (bool)nextInt(2);
}

