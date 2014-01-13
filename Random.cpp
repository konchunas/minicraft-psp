//#include <psprtc.h>

#include "Random.h"

#include <stdlib.h>
#include <time.h>
#include <math.h>
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
	//rather slow routine
	double x = 0;
	for(ushort i = 0; i < 25; ++i)
	{
		x += nextFloat();
	}

	x -= 25 / 2.0;
	x /= sqrt(25 / 12.0);

	return x;
}

bool Random::nextBoolean()
{
	return (bool)nextInt(2);
}

