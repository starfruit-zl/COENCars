#include "Car.h"
using namespace std;

int Car::idManager = 1;

Car::Car(std::string type1, bool IsCarAvailable) : type(type1), isCarAvailable(IsCarAvailable) {
	id = idManager++;
}
//add idManager here too

Car::Car() {
	id = idManager++;
	type = {};
	isCarAvailable = false;
}

//No set for ID, as it is managed and controlled by the system.

int Car::getID() {
	return id;
}

void Car::setType(std::string type1) {
	type = type1;
	return;
}

std::string Car::getType() {
	return type;
}

void Car::setAvailability(bool availability) {
	isCarAvailable = availability;
	return;
}

bool Car::getAvailability() {
	return isCarAvailable;
}

Date Car::getPickUp() {
	return pickUp;
}
Date Car::getDropOff() {
	return dropOff;
}

void Car::setPickUp(Date TO) {
	pickUp = TO;
}
void Car::setDropOff(Date TI) {
	dropOff = TI;
}

void Car::print() {
	std::cout << "\nID: " << id << "\nType: " << type << "\nAvailability: ";
	if (isCarAvailable) std::cout << "Yes";
	else std::cout << "No";
}

StandardCar::StandardCar(std::string type1, bool IsCarAvailable) : Car(type1, IsCarAvailable) {}

StandardCar::StandardCar() : Car() {};

void StandardCar::print() {
	cout << "\n\nStandard Car:";
	Car::print();
}

LuxuryCar::LuxuryCar(std::string type1, bool IsCarAvailable) : Car(type1, IsCarAvailable) {}

LuxuryCar::LuxuryCar() : Car() {};

void LuxuryCar::print() {
	std::cout << "\n\nLuxury Car:";
	Car::print();
}