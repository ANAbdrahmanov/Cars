#pragma once
#include <memory>

class Car;
class IPublisher;
class IEngine;

class CarFactory {
public:
	virtual ~CarFactory() {}
	virtual std::shared_ptr<Car> CreateCar(std::shared_ptr<IPublisher>) = 0;
protected:
	int SpecifyPower();
	std::unique_ptr<IEngine> ProduceEngine();

	int getNextRandom(int, int);

	enum EtEngineType
	{
		COMBUSTION,
		DIESEL,
		ELECTRIC,
		JET,
		BROKEN,
		MAX_ENGINE
	};
};
