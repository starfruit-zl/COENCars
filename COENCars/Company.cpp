#include "Company.h"

using namespace std;

Company::Company(string name1) {
	name = name1;
	cars = new Car * [1000];
	amountCars = 0;
}

Company::Company(string name1, Car** cars1, int ammountCars1){
	name = name1;
	cars = cars1;
	amountCars = ammountCars1;
}

void Company::setName(string name1) {
	name = name1;

	return;
}

string Company::getName() {
	return name;
}

void Company::addCar() {
	string input;
	while (true) { //last input.
		std::cout << "\nSelect the type of Car (Standard or Luxury):";
		std::cin >> input;

		if (input[0] == 'S' || 's') addCar();
		else if (input[0] == 'L' || 'l') addCar();
	}
}

void Company::addCar(Car* newCar) {
	cars[amountCars++] = newCar;
}

Car* Company::getCar() {

}

Car* Company::getCar(int){

}
void Company::removeCar(){

}