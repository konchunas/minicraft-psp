#ifndef LEVELGEN_H_
#define LEVELGEN_H_

#include "../Random.h"
#include "tile/Tile.h"

typedef unsigned short ushort;

class LevelGen {
public:
	LevelGen(int w, int h, int featureSize);
	virtual ~LevelGen();
	double * values;
	static ushort ** createAndValidateTopMap(int w, int h);
	//static ushort ** createAndValidateUndergroundMap(int w, int h, int depth);
	static Random * random;

private:
	int w, h;
	int widthMinusOne, heightMinusOne;


	inline double sample(int x, int y);
	inline void setSample(int x, int y, double sample);
	static ushort ** createTopMap(int w, int h);
	//static ushort ** createUndergroundMap(int w, int h, int depth);
};

#endif /* LEVELGEN_H_ */
