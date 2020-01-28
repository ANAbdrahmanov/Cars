#include <string>
#include <iostream>
#include <memory>

#include "Car.h"
#include "IPublisher.h"
#include "CMeteocenter.h"
#include "IEngine.h"

int Car::getPower() const
{
	return m_nPower;
}

std::string Car::getModel() const
{
	return m_sModel;
}

void Car::setPower(int power) {
	m_nPower = power;
}

void Car::setModel(const std::string& model) {
	m_sModel = model;	
}

void Car::setEngine(std::unique_ptr<IEngine>&& eng)
{
	m_pCarEngine = std::move(eng);
}

Car::Car(const std::string& m)
{
	m_sModel = m;
}

Car::Car(int p, const std::string& m)
	:Car(m)
{
	m_nPower = p;
}

Car::Car(int p, const std::string& m, std::shared_ptr<IPublisher> pubpt) 
	: Car(p, m)
{
	m_pPublisher = std::weak_ptr<IPublisher>(pubpt);
}

Car::Car(int p, const std::string& m, std::shared_ptr<IPublisher> pubpt, std::unique_ptr<IEngine> engpt)
	:Car(p,m,pubpt)
{
	m_pCarEngine = std::move(engpt);
}

Car::Car(const Car& c) 
	:m_nPower(c.m_nPower),
	m_sModel(c.m_sModel),
	m_pPublisher(c.m_pPublisher)
{
	*m_pCarEngine = *c.m_pCarEngine;
}

Car::Car(Car&& c)
	:m_nPower(std::move(c.m_nPower)),
	m_sModel(std::move(m_sModel)),
	m_pPublisher(std::move(c.m_pPublisher)),
	m_pCarEngine(std::move(c.m_pCarEngine))
{
} 

Car::~Car() 
{
	if (auto pt = m_pPublisher.lock()) 
	{
		pt->Detach(shared_from_this());
	}
}

Car& Car::operator=(const Car& c) 
{
	m_nPower = c.m_nPower;
	m_sModel = c.m_sModel;
	*m_pCarEngine = *c.m_pCarEngine;
	m_pPublisher = c.m_pPublisher;
	return *this;
}

Car& Car::operator=(Car&& c) 
{
	m_nPower = std::move(c.m_nPower);
	m_sModel = std::move(c.m_sModel);
	m_pCarEngine = std::move(c.m_pCarEngine);
	m_pPublisher = std::move(c.m_pPublisher);
	return *this;
}

bool Car::operator==(const Car& c) const 
{ ///car engine???
		return (c.m_sModel == m_sModel) && (c.m_nPower == m_nPower) 
			&& (m_pPublisher.lock() == c.m_pPublisher.lock());
}

bool Car::operator!=(const Car& c) const 
{
	return !(*this == c);
}

void Car::MeteoCenterInfo() const {
	std::cout << "Wind is " << CMeteocenter::GetInstance().GetWindSpeed()
		<< "m/s and the temperature is " << CMeteocenter::GetInstance().GetTemperature()
		<< "degrees" << std::endl;
}

void Car::Update(const std::string& message)
{
	std::cout << m_sModel << " recieved:" << message << std::endl;
}

void Car::MakeSureToAttach() {
	if (auto pt = m_pPublisher.lock())
	{
		pt->Attach(shared_from_this());
	}
}