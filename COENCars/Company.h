#pragma once

#include <string>
#include <sstream>
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
	int searchCustomer(string);
	string recieveString(string);
	int recieveInt(string message);
	int streamToInt(std::istringstream&);

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

	void addCustomer(Customer*);

	void printCar();
	void printCar(int);
	void printAllCars();
	void printCustomer();
	void printCustomer(int);
	void printAllCustomers();
	void printAvalableCars();

	void rentCar();
	void rentCar(Car*,Customer*);
	void returnCar();

	//customer interactions?
};

#endif // !CAR
