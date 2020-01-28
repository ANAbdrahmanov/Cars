#include "Subaru.h"
#include <iostream>

Subaru::Subaru(int p)
	:Car(p, "Subaru")
{
}

Subaru::Subaru(int p, std::shared_ptr<IPublisher> pubpt, std::unique_ptr<IEngine> engpt)
	:Car(p, "Subaru", pubpt, std::move(engpt))
{
}

Subaru* Subaru::clone() const {
	return new Subaru(*this);
}

void Subaru::Drive() {
	std::cout << "Subaru: I don't want to do something without good fuel" << std::endl;
	m_pCarEngine->Sound();
	MeteoCenterInfo();
}