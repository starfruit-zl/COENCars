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

};

#endif // !CUSTOMER
