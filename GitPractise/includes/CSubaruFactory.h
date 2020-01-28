#pragma once
#include "CarFactory.h"

class CSubaruFactory : public CarFactory
{
public:
	std::shared_ptr<Car> CreateCar(std::shared_ptr<IPublisher>) override;
};

