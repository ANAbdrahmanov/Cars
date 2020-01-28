#include "CarFactory.h"
#include "Car.h"
#include <random>
#include "CCombustionEngine.h"
#include "CDieselEngine.h"
#include "CElectricEngine.h"
#include "CJetEngine.h"
#include "CBrokenEngine.h"

int CarFactory::SpecifyPower() {

	return  getNextRandom(0, Car::kLimiter);
}

std::unique_ptr<IEngine> CarFactory::ProduceEngine() {
	int randomEngine = getNextRandom(0, MAX_ENGINE);
	switch (randomEngine) {
	case COMBUSTION:
		return std::unique_ptr<CCombustionEngine>(new CCombustionEngine());
		break;
	case DIESEL:
		return std::unique_ptr<CDieselEngine>(new CDieselEngine());
		break;
	case ELECTRIC:
		return std::unique_ptr<CElectricEngine>(new CElectricEngine());
		break;
	case JET:
		return std::unique_ptr<CJetEngine>(new CJetEngine());
		break;
	case BROKEN:
		return std::unique_ptr<CBrokenEngine>(new CBrokenEngine());
		break;
	default:
		break;
	}
}

int CarFactory::getNextRandom(int min, int max) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(min, max - 1);
	return uni(rng);
}