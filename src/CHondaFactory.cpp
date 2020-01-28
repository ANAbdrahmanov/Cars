#include "CHondaFactory.h"
#include "Honda.h"

std::shared_ptr<Car> CHondaFactory::CreateCar(std::shared_ptr<IPublisher> pubpt) {
	auto result = std::make_shared<Honda>(SpecifyPower(), pubpt, ProduceEngine());
	result->MakeSureToAttach();
	return result;
}