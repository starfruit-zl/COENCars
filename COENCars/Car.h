#pragma once

using namespace std;
#include <string>
#include <iostream>

#ifndef CAR
#define CAR

class Car {

private:
	int id;

	std::string type;

	bool isCarAvailable;

public:
	Car(int id1, std::string type1, bool IsCarAvailable);

	void setID(int id1);
	int getID();

	void setType(std::string type1);
	std::string getType();

	void setAvailability(bool);
	bool getAvailability();

	virtual void print();
};

class StandardCar : public Car{

public:
	StandardCar(int id1, std::string type1, bool IsCarAvailable);
	virtual void print();
};

class LuxuryCar : public Car {

public:
	LuxuryCar(int id1, std::string type1, bool IsCarAvailable);
	virtual void print();
};

#endif // CAR