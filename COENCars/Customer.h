#pragma once

#include "Car.h"
#include <string>
#include <iostream>
using namespace std;

#ifndef CUSTOMER
#define CUSTOMER

class Customer {
private:
	int id;
	string name;
	string address;
	string phoneNum;
	Car** carsRented;
	int rentedNum;

public:
	Customer();
	Customer(int, string, string, string);
	int getId();
	string getName();
	void setName(string);
	string getAdress();
	void setAdress(string);
	string getPhoneNum();
	void setPhoneNum(string);
	int getRentedNum();
	void printCarsRented();
};

#endif // !CUSTOMER
