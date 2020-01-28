#include <iostream>
#include <vector>
#include <memory>
#include "CRandomCarFactory.h"
#include "Car.h"
#include "Radio.h"


#define CARS_COUNT 10

void Race(const std::vector<std::shared_ptr<Car>>& cars) {
	for (int i = 0; i < 5; i++) {
		std::cout << "Round " << i + 1 << std::endl;
		for (auto it = cars.begin(); it != cars.end(); ++it) {
			(*it)->Drive();
		}
		std::cout << "\n";
	}
}

int main() {
	std::vector<std::shared_ptr<Car>> cars;
	std::shared_ptr<IPublisher> pRadio = std::make_shared<Radio>();
	auto randomCarFactory = std::unique_ptr<CarFactory>(new CRandomCarFactory());
	for (int i = 0; i < CARS_COUNT; i++) {
		cars.push_back(randomCarFactory->CreateCar(pRadio));
	}
	Race(cars);
	std::cin.get();
	return 0;
}