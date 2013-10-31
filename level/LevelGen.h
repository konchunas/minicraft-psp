#ifndef LEVELGEN_H_
#define LEVELGEN_H_

#include "../Random.h"
#include "tile/Tile.h"

typedef unsigned short ushort;

class LevelGen {
public:
	LevelGen(int w, int h, int featureSize);
	virtual ~LevelGen();
	float * values;
	static ushort ** createAndValidateTopMap(int w, int h);
	static ushort ** createAndValidateUndergroundMap(int w, int h, int depth);
	static ushort ** createAndValidateSkyMap(int w, int h);
	static Random * random;

private:
	int w, h;
	int widthMinusOne, heightMinusOne;


	inline float sample(int x, int y);
	inline void setSample(int x, int y, float sample);
	static ushort ** createTopMap(int w, int h);
	static ushort ** createUndergroundMap(int w, int h, int depth);
	static ushort ** createSkyMap(int w, int h);
};

#endif /* LEVELGEN_H_ */
