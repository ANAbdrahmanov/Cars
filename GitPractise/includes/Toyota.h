#pragma once
#include "Car.h"


class Toyota : public Car {
public:
	int getSpeed() const;
	void setSpeed(int);

	//Toyota(int, std::shared_ptr<IPublisher>, std::unique_ptr<IEngine>);
	Toyota(int, std::shared_ptr<IPublisher>, std::unique_ptr<IEngine>, int);

	Toyota(const Toyota&);
	Toyota(Toyota&&);

	Toyota& operator=(const Toyota&);
	Toyota& operator=(Toyota&&);

	bool operator==(const Toyota&) const;
	bool operator!=(const Toyota&) const;

	Toyota* clone() const override;

	void Drive() override;

protected:
	int speed;
	explicit Toyota(int);
};