#include "Customer.h"
using namespace std;

int Customer::idManager(1);

Customer::Customer() {
	id = idManager++;
	name = {};
	address = {};
	phoneNum = {};
	carsRented = new Car * [1000];
	rentedNum = 0;
}

Customer::Customer(string Name, string Address, string PhoneNum) {
	id = idManager++;
	name = Name;
	address = Address;
	phoneNum = PhoneNum;
	carsRented = new Car * [1000];
	rentedNum = 0;
}

Customer::~Customer() {
	delete[] carsRented;
	carsRented = nullptr;
}

int Customer::getId() {
	return id;
}

string Customer::getName() {
	return name;
}

void Customer::setName(string Name) {
	name = Name;
	return;
}

string Customer::getAddress() {
	return address;
}

void Customer::setAddress(string Address) {
	address = Address;
	return;
}

string Customer::getPhoneNum() {
	return phoneNum;
}

void Customer::setPhoneNum(string Phone) {
	phoneNum = Phone;
}

int Customer::getRentedNum() {
	return rentedNum;
}

void Customer::addCar(Car* newCar) {
	carsRented[rentedNum++] = newCar;
}

void Customer::removeCar(int ID) {
	for (int i(0); i < rentedNum; i++) {
		if (carsRented[i]->getID() == ID) {
			for (int j(i); j < rentedNum; j++) {
				carsRented[j] = carsRented[j + 1];
			}
			cout << "\nCar with ID: " << ID << ", removed from " << name << "'s rented cars";
			return;
		}
	}
	cout << "\nCould not remove car, ID not found!";
	return;
}

void Customer::printCarsRented() {
	for (int i(0); i < rentedNum; i++) {
		carsRented[i]->print();
		cout << "\n";
	}

	if (rentedNum == 0)
		cout << "\nNo Cars rented";
	return;
}

RegularCustomer::RegularCustomer() : Customer() {}

RegularCustomer::RegularCustomer(string Name, string Address, string PhoneNum) : Customer(Name, Address, PhoneNum) {}

void RegularCustomer::printCarsRented() {
	cout << "\nRegular Customer " << Customer::getName() << " rented cars:\n";
	Customer::printCarsRented();
}

CorporateCustomer::CorporateCustomer() : Customer() {}

CorporateCustomer::CorporateCustomer(string Name, string Address, string PhoneNum) : Customer(Name, Address, PhoneNum) {}

void CorporateCustomer::printCarsRented() {
	cout << "\nCorporate Customer " << Customer::getName() << " cars rented:\n";
	Customer::printCarsRented();
}