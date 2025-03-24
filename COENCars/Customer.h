#pragma once

#include "Car.h"
#include <string>
#include <iostream>
using namespace std;

#ifndef CUSTOMER
#define CUSTOMER

class Customer {
private:
	static int idManager;
	int id;
	string name;
	string address;
	string phoneNum;
	Car** carsRented;
	int rentedNum;

public:
	Customer();
	Customer(string, string, string);
	~Customer();
	int getId();
	string getName();
	void setName(string);
	string getAddress();
	void setAddress(string);
	string getPhoneNum();
	void setPhoneNum(string);
	int getRentedNum();
	void addCar(Car*);
	void removeCar(int);
	virtual void printCarsRented();
};

class RegularCustomer : Customer {
public:
	RegularCustomer();
	RegularCustomer(string, string, string);
	virtual void printCarsRented();
};

class CorporateCustomer : Customer {
	CorporateCustomer();
	CorporateCustomer(string, string, string);
	virtual void printCarsRented();
};
#endif // !CUSTOMER
