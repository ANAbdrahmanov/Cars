#pragma once
#include <string>
#include <memory>
#include "IObserver.h"
#include "IEngine.h"

class IPublisher;

class Car : public IObserver, public std::enable_shared_from_this<Car> {
public:

	int getPower() const;
	std::string getModel() const;
	void setPower(int);
	void setModel(const std::string&);
	void setEngine(std::unique_ptr<IEngine>&&);

	Car(int, const std::string&, std::shared_ptr<IPublisher>, std::unique_ptr<IEngine>);

	virtual ~Car();

	Car(const Car&);
	Car(Car&&);

	virtual Car* clone() const = 0; 

	Car& operator=(const Car&);
	Car& operator=(Car&&);

	bool operator==(const Car&) const;
	bool operator!=(const Car&) const;

	virtual void Drive() = 0;

	void Update(const std::string&);

	void MakeSureToAttach();

	static const int kLimiter = 100;

protected:
	explicit Car(const std::string& m);
	Car(int, const std::string& m);
	Car(int, const std::string&, std::shared_ptr<IPublisher>);
	void MeteoCenterInfo() const;

	int m_nPower;
	std::string m_sModel;
	std::unique_ptr<IEngine> m_pCarEngine;
	std::weak_ptr<IPublisher> m_pPublisher;
};