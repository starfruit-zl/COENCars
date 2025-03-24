#pragma once

#include <string>
#include "Car.h"
using namespace std;

#ifndef COMPANY
#define COMPANY
class Company {
private:
	string name;
	Car** cars;
	int amountCars;
public:
	Company(string);
	Company(string, Car**, int);
	void setName(string);
	string getName();
	void addCar(); //initializes car.
	void addCar(Car*);
	Car* getCar();
	Car* getCar(int);
	void removeCar(); //uses getCar() to find.
	//customer interactions?
};

#endif // !CAR
