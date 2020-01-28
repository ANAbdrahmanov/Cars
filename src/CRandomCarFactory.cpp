#include "CRandomCarFactory.h"
#include "CHondaFactory.h"
#include "CSubaruFactory.h"
#include "CToyotaFactory.h"
#include <ctime>

std::shared_ptr<Car> CRandomCarFactory::CreateCar(std::shared_ptr<IPublisher> pubpt) {
	int carType = getNextRandom(0, MAX_CAR);
	switch (carType) {
	case HONDA:
		return CHondaFactory().CreateCar(pubpt);
		break;
	case TOYOTA:
		return CToyotaFactory().CreateCar(pubpt);
		break;
	case SUBARU:
		return CSubaruFactory().CreateCar(pubpt);
		break;
	default:
		break;
	}
}