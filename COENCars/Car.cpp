#include "Car.h"
using namespace std;

Car::Car(int id1, std::string type1, bool IsCarAvailable) : id(id1), type(type1), isCarAvailable(IsCarAvailable) {}

void Car::setID(int id1) {
	id = id1;
	return;
}

int Car::getID() {
	return id;
}

void Car::setType(std::string type1){
    type = type1;
	return;
}

std::string Car::getType(){
    return type;
}

void Car::setAvailability(bool availability) {
	isCarAvailable = availability;
	return;
}

bool Car::getAvailability() {
	return isCarAvailable;
}

void Car::print() {
	std::cout << "\nID: " << id << "\nType: " << type << "\nAvailability: ";
	if (isCarAvailable) std::cout << "Yes";
	else std::cout << "No";
}

StandardCar::StandardCar(int id1, std::string type1, bool IsCarAvailable) : Car(id1, type1, IsCarAvailable) {}

void StandardCar::print(){
    cout << "\n\nStandard Car:\n";
    Car::print();
}

LuxuryCar::LuxuryCar(int id1, std::string type1, bool IsCarAvailable) : Car(id1, type1, IsCarAvailable) {}

void LuxuryCar::print() {
	std::cout << "\n\nLuxury Car: \n";
	Car::print();
}