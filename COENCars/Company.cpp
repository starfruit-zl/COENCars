#include "Company.h"
#include <vector>

using namespace std;

int Company::recieveInt(string message) {
	int input;
	std::cout << '\n' + message + "->";
	std::cin >> input;

	return input;
}

string Company::recieveString(string message) {
	std::cout << '\n' + message + "->";
	std::cin >> message;

	return message;
}

Company::Company(string name1) {
	name = name1;
	cars = new Car * [1000];
	amountCars = 0;
}

Company::Company(string name1, Car** cars1, int ammountCars1){
	name = name1;
	cars = cars1;
	amountCars = ammountCars1;
}

void Company::setName(string name1) {
	name = name1;

	return;
}

string Company::getName() {
	return name;
}

int Company::getAmount() {
	return amountCars;
}

void Company::addCar() {
	string input;
	std::vector<string> inputStore;

	inputStore.push_back(recieveString("Input the car type"));
	
	while (true) { //last input.
		input = recieveString("Select the class of Car(Standard or Luxury)");

		if (input[0] == 'S' || input[0] == 's') addCar(new StandardCar(inputStore[0], true));
		else if (input[0] == 'L' || input[0] == 'l') addCar(new LuxuryCar(inputStore[0], true));
		else std::cout << "\nInvalid class, please try again.";
	}
}

void Company::addCar(Car* newCar) {
	cars[amountCars++] = newCar;
	std::cout << "\nThe new car has been registered with ID: " << newCar->getID();
	return;
}

Car* Company::getCar() {
	return getCar(recieveInt("Input the Rental Car ID"));
}

Car* Company::getCar(int ID){
	int it = searchCar(ID);
	if (it != -1){
		return cars[it];
	}
	cout << "\nInvalid Input";
	getCar();
}

void Company::removeCar() {
	removeCar(recieveInt("Input the Rental Car ID"));
}

void Company::removeCar(int ID) {
	int it = searchCar(ID);
	if (it != -1) {
		for (int i(it); i < amountCars; i++) {
			cars[i] = cars[i + 1];
		}
		--amountCars;
		return;
	}
	cout << "\nInvalid Input";
	getCar();
}

int Company::searchCar(int ID) {
	for (int i(0); i < amountCars; i++) {
		if (cars[i]->getID() == ID) {
			return i;
		}
	}
	return -1;
}

void Company::printCar() {
	printCar((recieveInt("Input the Rental Car ID")));
}

void Company::printCar(int ID){
	int it = searchCar(ID);
	if (it != -1) {
		cars[it]->print();

		return;
	}
	
	cout << "\nInvalid ID";
	printCar();
}

void Company::printAllCars(){
	cout << "\nAll Cars Owned by " << name << ":";
	
	if (amountCars == 0){
		cout << "\nNo cars currently owned";
		return;
	}

	for (int i(0); i < amountCars; i++){
		cars[i]->print();
	}
	return;
}