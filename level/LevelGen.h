#ifndef LEVELGEN_H_
#define LEVELGEN_H_

#include "../Random.h"
#include "tile/Tile.h"

typedef unsigned char byte;

class LevelGen {
public:
	LevelGen(int w, int h, int featureSize);
	virtual ~LevelGen();
	float * values;
	static byte ** createAndValidateTopMap(int w, int h);
	static byte ** createAndValidateUndergroundMap(int w, int h, int depth);
	static byte ** createAndValidateSkyMap(int w, int h);
	static Random * random;

private:
	int w, h;
	int widthMinusOne, heightMinusOne;


	inline float sample(int x, int y);
	inline void setSample(int x, int y, float sample);
	static byte ** createTopMap(int w, int h);
	static byte ** createUndergroundMap(int w, int h, int depth);
	static byte ** createSkyMap(int w, int h);
};

#endif /* LEVELGEN_H_ */
