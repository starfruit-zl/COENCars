#include "Customer.h"
using namespace std;

static int ids(1);

Customer::Customer() {
	id = ids++;
	name = {};
	address = {};
	phoneNum = {};
	carsRented = new Car*[1000];
	rentedNum = 0;
}

Customer::Customer(string Name, string Address, string PhoneNum) {
	id = ids++;
	name = Name;
	address = Address;
	phoneNum = PhoneNum;
	carsRented = new Car * [1000];
	rentedNum = 0;
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

void Customer::printCarsRented() {
	for (int i(0); i < rentedNum; i++) {
		carsRented[i]->print();
		cout << "\n";
	}

	if (rentedNum == 0)
		cout << "\nNo Cars rented";
	return;
}

RegularCustomer::RegularCustomer() : Customer(){}

RegularCustomer::RegularCustomer(string Name, string Address, string PhoneNum) : Customer(Name, Address, PhoneNum){}

void RegularCustomer::printCarsRented() {
	cout << "\nRegular Customer " << Customer::getName() << " rented cars:\n";
	Customer::printCarsRented();
}

CorporateCustomer::CorporateCustomer() : Customer(){}

CorporateCustomer::CorporateCustomer(string Name, string Address, string PhoneNum) : Customer(Name, Address, PhoneNum){}

void CorporateCustomer::printCarsRented() {
	cout << "\nCorporate Customer " << Customer::getName() << " cars rented:\n";
	Customer::printCarsRented();
}