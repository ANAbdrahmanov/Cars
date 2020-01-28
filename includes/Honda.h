#pragma once
#include "Car.h"

class Honda : public Car {
public:
	Honda(int, std::shared_ptr<IPublisher> pubpt, std::unique_ptr<IEngine> engpt);

	Honda* clone() const override;

	void Drive() override;

protected:
	explicit Honda(int p);
};
