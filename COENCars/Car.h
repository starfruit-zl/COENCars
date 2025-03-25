#pragma once

using namespace std;
#include <string>
#include <iostream>
#include "Date.h"

#ifndef CAR
#define CAR

class Car {

private:
	static int idManager;

	int id;

	std::string type;

	bool isCarAvailable;

	Date pickUp;

	Date dropOff;



public:
	Car(std::string type1, bool IsCarAvailable);
	Car();

	//no set for ID, as it is managed by the system
	int getID();

	void setType(std::string type1);
	std::string getType();

	void setAvailability(bool);
	bool getAvailability();

	Date getPickUp();
	Date getDropOff();

	void setPickUp(Date);
	void setDropOff(Date);

	virtual void print();
};

class StandardCar : public Car {

public:
	StandardCar(std::string type1, bool IsCarAvailable);
	StandardCar();
	virtual void print();
};


class LuxuryCar : public Car {

public:
	LuxuryCar(std::string type1, bool IsCarAvailable);
	LuxuryCar();
	virtual void print();
};

#endif