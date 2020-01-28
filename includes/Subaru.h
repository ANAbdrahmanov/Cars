#pragma once
#include "Car.h"

class Subaru : public Car{
public:
	Subaru(int, std::shared_ptr<IPublisher> pubpt, std::unique_ptr<IEngine> engpt);

	Subaru* clone() const override;

	void Drive() override;

protected:
	explicit Subaru(int p);
};