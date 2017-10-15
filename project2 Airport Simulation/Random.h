#ifndef _RANDOM_H_
#define _RANDOM_H_
class Random {
public:
	Random(bool pseudo = true);
	double random_real();
	int poisson(double mean);
	~Random();
private:
	int reseed();
	int seed, multiplier, add_on;

};
#endif