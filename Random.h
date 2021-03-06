#ifndef RANDOM_H_
#define RANDOM_H_

class Random {
public:
	Random();
	virtual ~Random();
	int nextInt(int);
	float nextFloat();
	double nextGaussian();
	bool nextBoolean();
};

#endif /* RANDOM_H_ */
