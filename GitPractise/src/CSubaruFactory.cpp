#include "CSubaruFactory.h"
#include "Subaru.h"

std::shared_ptr<Car> CSubaruFactory::CreateCar(std::shared_ptr<IPublisher> pubpt) {
	auto result = std::make_shared<Subaru>(SpecifyPower(), pubpt, ProduceEngine());
	result->MakeSureToAttach();
	return result;
}
