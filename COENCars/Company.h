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
	int searchCar(int);
	string recieveString(string);
	int recieveInt(string message);
public:
	Company(string);
	Company(string, Car**, int);
	void setName(string);
	string getName();
	int getAmount();
	void addCar(); //initializes car.
	void addCar(Car*);
	Car* getCar();
	Car* getCar(int);
	void removeCar(); //uses getCar() to find.
    void removeCar(int);
	void printCar();
	void printCar(int);
	void printAllCars();

	
	//customer interactions?
};

#endif // !CAR
