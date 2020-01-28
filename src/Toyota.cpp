#include "Toyota.h"
#include "CMeteocenter.h"
#include <ctime>
#include <iostream>

int Toyota::getSpeed() const
{
	return speed;
}

void Toyota::setSpeed(int s)
{
	speed = s;
}

Toyota::Toyota(int p)
	:Car(p, "Toyota")
{
	//speed = (std::rand() % kLimiter) * p; ///this actually violates single responsibility principle
}

//Toyota::Toyota(int p, std::shared_ptr<IPublisher> pubpt, std::unique_ptr<IEngine> engpt)
//	:Car(p, "Toyota", pubpt, std::move(engpt))
//{
//	speed = (std::rand() % kLimiter) * p;
//}

Toyota::Toyota(int p, std::shared_ptr<IPublisher> pubpt, std::unique_ptr<IEngine> engpt, int s)
	: Car(p, "Toyota", pubpt, std::move(engpt))
{
	speed = s;
}

Toyota::Toyota(const Toyota& t)
	:Car(t.m_nPower, t.m_sModel, t.m_pPublisher.lock())
{
	speed = t.speed;
	*m_pCarEngine = *t.m_pCarEngine;
}


Toyota::Toyota(Toyota&& t)
	:Car(std::move(t.m_nPower),std::move(t.m_sModel),std::move(t.m_pPublisher.lock()),std::move(t.m_pCarEngine)),
	speed(std::move(t.speed))
{
}

Toyota* Toyota::clone() const 
{
	return new Toyota(*this);
}

Toyota& Toyota::operator=(const Toyota& t)
{
	Car::operator=(t);
	speed = t.speed;
	return *this;
}

Toyota& Toyota::operator=(Toyota&& t)
{
	speed = std::move(t.speed);
	Car::operator=(std::move(t));
	return *this;
}


bool Toyota::operator==(const Toyota& t) const
{
	return Car::operator==(t) && (t.speed == speed);
}

bool Toyota::operator!=(const Toyota& t) const
{
	return !(*this == t);
}

void Toyota::Drive() 
{
	std::srand(unsigned(std::time(0)));
	speed += (std::rand() % kLimiter) * m_nPower;
	std::cout << "Toyota: " << speed << std::endl;
	m_pCarEngine->Sound();
	MeteoCenterInfo();
}