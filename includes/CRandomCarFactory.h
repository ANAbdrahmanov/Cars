#pragma once
#include "CarFactory.h"

class CRandomCarFactory : public CarFactory
{
public:
	std::shared_ptr<Car> CreateCar(std::shared_ptr<IPublisher>) override;
protected:
	enum etCars {
		HONDA = 0,
		TOYOTA,
		SUBARU,
		MAX_CAR
	};
};

