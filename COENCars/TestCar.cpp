#include "Car.h"


int main() {

	Car** cars = new Car*[10]; //if not dynamically declared.

	Car* temp = new LuxuryCar("Cadillac", true);

	cars[1] = temp;
	
	std::cout << "\n*TEST DIALOGUE* Testing print on a dynamically initialized car object, of child-type Luxury Car.";
	temp->print();

	std::cout << "\n\n*TEST DIALOGUE* Testing that it may be stored in an array of Car pointers, and then printed from the index.";
	cars[1]->print();

	cars[2] = new StandardCar("Chevrolet", false);
	std::cout << "\n\n*TEST DIALOGUE* Testing print on a Standard Car in the array of Car pointers, demonstrating the different output and that it will be unnavailable if declared as such in the constructor.\n";
	cars[2]->print();

	std::cout << "\n\n*TEST DIALOGUE* Testing setters on the luxury car: Changing type to lincoln, and making unnavailable.";

	cars[1]->setType("Lincoln");
	cars[1]->setAvailability(false);

	cars[1]->print();

	std::cout << "\n\n*TEST DIALOGUE* Testing getters on the luxury car: Displaying each component in line without print."
		<< "\nID: " << cars[1]->getID() << " Type: " << cars[1]->getType() << " Available?: " << cars[1]->getAvailability();
	
	//do we want a copy constructor for the classes? Perhaps to modify the it so a car can become luxury after a while? Or depreciate
	//in value making it standard?
	std::cout << "\n\n*TEST DIALOGUE* Clearing data";
	delete temp;

	temp = nullptr;

	delete[] cars;

	cars = nullptr;

	return 0;
}