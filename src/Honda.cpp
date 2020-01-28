#include "Honda.h"
#include <ctime>
#include <iostream>

Honda::Honda(int p)
	:Car(p, "Honda")
{
}

Honda::Honda(int p, std::shared_ptr<IPublisher> pubpt, std::unique_ptr<IEngine> engpt)
	: Car(p, "Honda", pubpt, std::move(engpt))
{
}

Honda* Honda::clone() const {
	return new Honda(*this);
}

void Honda::Drive() {
	std::srand(unsigned(std::time(0)));
	std::cout << "Honda: " << (std::rand() % kLimiter) * m_nPower << std::endl;
	m_pCarEngine->Sound();
	MeteoCenterInfo();
}