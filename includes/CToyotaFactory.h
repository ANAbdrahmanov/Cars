#pragma once
#include "CarFactory.h"

class CToyotaFactory : public CarFactory
{
public:
	std::shared_ptr<Car> CreateCar(std::shared_ptr<IPublisher>) override;
private:
	int SpecifySpeed(int);
};

