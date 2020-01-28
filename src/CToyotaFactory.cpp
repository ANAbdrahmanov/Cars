#include "CToyotaFactory.h"
#include "Toyota.h"
#include <ctime>


std::shared_ptr<Car> CToyotaFactory::CreateCar(std::shared_ptr<IPublisher> pubpt) {
	int power = SpecifyPower();
	auto result = std::make_shared<Toyota>(power, pubpt, ProduceEngine(), SpecifySpeed(power));
	result->MakeSureToAttach();
	return result;
}

int CToyotaFactory::SpecifySpeed(int p) {
	return getNextRandom(0, Car::kLimiter) * p;
}