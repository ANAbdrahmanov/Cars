#pragma once
#include "CarFactory.h"

class CHondaFactory : public CarFactory
{
public:
	std::shared_ptr<Car> CreateCar(std::shared_ptr<IPublisher>) override;
};

