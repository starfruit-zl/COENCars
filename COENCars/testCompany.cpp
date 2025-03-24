#include <iostream>
#include "Company.h"
#include "Car.h"

void testCompany(Company, string, Car**, int, int);

int main() {
	Car** cars = new Car * [1000];
	string name("Jimmy");
	Company A(name);
	cout << "\nTesting Null constructor:";
	testCompany(A, name, cars, 0, 1);

	cars[0] = new LuxuryCar("Toyota", true);
	cars[1] = new StandardCar("Lexus", true);
	Company B(name, cars, 2);
	cout << "\nTesting constructor with variables:";
	testCompany(B, name, cars, 2, 4);
	cout << "\nPrinting all cars";
	B.printAllCars();
	B.printCar(2);

	return 0;
}

void testCompany(Company obj, string name, Car** cars, int amount, int carid){
	if (name != obj.getName()) std::cout << "\nError: getName mismatch";
	if (amount != 0) {
		for (int i = 0; i < amount-1; i++) {
			if (cars[i]->getID() != i + carid - amount) {
				std::cout << "\nError:  getID mismatch";
				break;
			}
		}
	}
	if (amount != obj.getAmount()) std::cout << "\nError: getAmount mismatch!";
	std::cout.setstate(std::ios_base::failbit); //disable the output of the ID, since it won't exist for long, and not informative for test.
	obj.addCar(new StandardCar("MINI Cooper", true));
	std::cout.clear();
	if (obj.getCar(carid)->getType() != "MINI Cooper") std::cout << "\nError: addCar mismatch!";
	obj.removeCar(carid);
	if (obj.getAmount() != amount) std::cout << "\nError: removeCar mismatch!";

	obj.setName("BIG BILL HELL'S CARS");
	if (obj.getName() != "BIG BILL HELL'S CARS") std::cout << "\nError: setName mismatch!";
}