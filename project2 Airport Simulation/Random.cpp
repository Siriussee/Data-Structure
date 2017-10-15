#include "Random.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <climits>
#include <cmath>

int max_int = INT_MAX;
Random::Random(bool pseudo)
{

	if (pseudo)
		seed = 1;
	else
		seed = time(NULL) % max_int;
	multiplier = 2743;
	add_on = 5923;
}
Random::~Random() {}
int Random::reseed()
{
	seed = seed * multiplier + add_on;
	return seed;
}
double Random::random_real()
{
	double max = max_int + 1.0;
	double temp = reseed();
	if (temp < 0)
		temp = temp + max;
	return temp / max;
}
int Random::poisson(double mean)
{
	double limit = exp(-mean);
	double product = random_real();
	int count = 0;
	while (product > limit)
	{
		count++;
		product *= random_real();
	}
	return count;
}
