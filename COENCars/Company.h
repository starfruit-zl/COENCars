#pragma once

#include <string>
#include "Car.h"
#include "Customer.h"
using namespace std;

#ifndef COMPANY
#define COMPANY
class Company {
private:
	string name;
	Car** cars;
	Customer** customers;
	int amountCars;
	int amountCustomers;
	int searchCar(int);
	int searchCustomer(int);
	string recieveString(string);
	int recieveInt(string message);
public:
	Company(string);
	~Company();
	void setName(string);
	string getName();
	int getAmountCars();
	int getAmountCustomers();
	void addCar(); //initializes car.
	void addCar(Car*);
	Car* getCar();
	Car* getCar(int);
	void removeCar(); //uses getCar() to find.
	void removeCar(int);
	void printCar();
	void printCar(int);
	void printAllCars();
	void printCustomer(int);
	void printAllCustomers();
	void rentCar();
	void rentCar(Car*,Customer*);

	//customer interactions?
};

#endif // !CAR
