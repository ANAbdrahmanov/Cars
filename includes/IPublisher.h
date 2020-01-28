#pragma once
#include <memory>

class IObserver;

class IPublisher {
public:
	virtual ~IPublisher(){}
	virtual void Attach(std::shared_ptr<IObserver>) = 0;
	virtual void Detach(std::shared_ptr<IObserver>) = 0;
	virtual void Notify() = 0;
};