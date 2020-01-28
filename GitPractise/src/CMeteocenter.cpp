#include "CMeteocenter.h"
#include <ctime>
#include <stdlib.h>

int CMeteocenter::GetWindSpeed() const{
	static int randomSeed(unsigned(time(0)));
	srand(randomSeed);
	return randomSeed = rand() % 20;
}

int CMeteocenter::GetTemperature() const{
	static int randomSeed(unsigned(time(0)));
	srand(randomSeed);
	return randomSeed = (rand() % 80) - 30;
}

CMeteocenter& CMeteocenter::GetInstance(){
	static CMeteocenter instance;
	return instance;
}