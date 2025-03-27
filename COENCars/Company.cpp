#include "Company.h"
#include "Customer.h"
#include <sstream>
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
	std::getline(cin, message);

	return message;
}

Company::Company(string name1) {
	name = name1;
	cars = new Car * [1000];
	customers = new Customer * [1000];
	amountCustomers = 0;
	amountCars = 0;
}

Company::~Company() {
	delete[] cars;
	delete[] customers;
	cars = nullptr;
	customers = nullptr;
	std::cout << "\nDestructor called";
}

void Company::setName(string name1) {
	name = name1;
	return;
}

string Company::getName() {
	return name;
}

int Company::getAmountCars() {
	return amountCars;
}

int Company::getAmountCustomers() {
	return amountCustomers;
}

void Company::addCar() {
	if (amountCars >= 1000) {
		cout << "\nCurrent ammount of cars full. Cannot add anymore cars!";
		return;
	}
	string input;
	std::vector<string> inputStore;

	inputStore.push_back(recieveString("Input the car type"));

	while (true) { //last input.
		input = recieveString("Select the class of Car(Standard or Luxury)");

		if (input[0] == 'S' || input[0] == 's') {
			addCar(new StandardCar(inputStore[0], true));
			break;
		}
		else if (input[0] == 'L' || input[0] == 'l') { 
			addCar(new LuxuryCar(inputStore[0], true)); 
			break;
		}
		else std::cout << "\nInvalid class, please try again.";
	}

	return;
}

void Company::addCar(Car* newCar) {
	if (amountCars >= 1000) {
		cout << "\nCurrent ammount of cars full. Cannot add anymore cars!";
		return;
	}
	cars[amountCars++] = newCar;
	std::cout << "\nThe new car has been registered with ID: " << newCar->getID();
	return;
}

Car* Company::getCar() {
	return getCar(recieveInt("Input the Rental Car ID"));
	cin.ignore();
}

Car* Company::getCar(int ID) {
	int it = searchCar(ID);
	if (it != -1) {
		return cars[it];
	}
	cout << "\nInvalid Input";
	getCar();
}

void Company::removeCar() {
	removeCar(recieveInt("Input the Rental Car ID"));
	cin.ignore();
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


void Company::rentCar() {
	int index = 0, indexCar = 0, selection = 0;
	std::vector<std::string> stringStore{ "" };;
	printAllCars();
	while (true) {
		indexCar = searchCar(recieveInt("Input the ID of the desired car from the list"));
		cin.ignore();
		if (indexCar != -1 )
			if (cars[indexCar]->getAvailability()) break;
		else std::cout << "\nSpecified ID does not appear in list, or car is unnavailable.";
		continue;
	}
	while (true) {
		stringStore[0] = (recieveString("Input the Renter's name"));
		index = searchCustomer(stringStore[0]);
		if (index != -1) {
			rentCar(cars[indexCar], customers[index]);
			break;
		}
		else {
			std::cout << "\nThe customer of the name " + stringStore[0] + " could not be found. How would you like to proceed?\n1.Register Customer.\n2.Search by ID.\n3.Re-input Customer.\nYour selection: ";
			std::cin >> selection;
			std::cin.ignore();
			switch (selection) {
			case 1:
				stringStore.push_back(recieveString("Enter the customer's address"));
				stringStore.push_back(recieveString("Enter the customer's phone number"));
				while (true) { //last input.
					stringStore.push_back(recieveString("Would you like to open a corporate account with us?(y/n)"));

					if (stringStore[3][0] == 'Y' || stringStore[3][0] == 'y') {
						addCustomer(new CorporateCustomer(stringStore[0], stringStore[1], stringStore[2]));
						break;
					}
					else if (stringStore[3][0] == 'N' || stringStore[3][0] == 'n') {
						addCustomer(new RegularCustomer(stringStore[0], stringStore[1], stringStore[2]));
						break;
					}
					else std::cout << "\nInvalid class, please try again.";
				}

				rentCar(cars[indexCar], customers[amountCustomers - 1]);
				break;
			case 2:
				index = searchCustomer(recieveInt("Input the Renter's ID"));
				std::cin.ignore();
				if (index == -1) {
					std::cout << "\nThe customer of the specified ID could not be found.";
					continue;
				}
				rentCar(cars[indexCar], customers[index]);
				break;
			case 3:
				continue;
				break;
			}

			break;
		}
	}
}

void Company::rentCar(Car* car1, Customer* customer1) {
	while (true) {
		std::istringstream date(recieveString("Enter the pickup date for the rental in format DD MM YYYY")); //uses istringstream to be able to process input as seperate components in getline.
		int d1 = streamToInt(date), m1 = streamToInt(date), y1 = streamToInt(date);
		car1->setPickUp(Date(d1, m1, y1));
		std::istringstream date1(recieveString("Enter the drop-off date for the rental in format DD MM YYYY"));
		int d2 = streamToInt(date1), m2= streamToInt(date1), y2 = streamToInt(date1);
		car1->setDropOff(Date(d2, m2, y2));
		
		if (car1->getDropOff() < car1->getPickUp()) {
			std::cout << "\nError: cannot dropoff car before picked-up";
			continue;
		}
		break;
	}
	car1->setAvailability(false);

	customer1->addCar(car1);
	
	std::cout << "\nRental confirmed! " << car1->getType() << " is reserved under the name of " << customer1->getName() <<"\nPickup date: " << car1->getPickUp().dateStr() << "\tDrop off date: " <<car1->getDropOff().dateStr();

	return;
}

void Company::returnCar() {
	int index = 0, indexCar = 0, carID = 0;;

	while (true) {
		index = searchCustomer(recieveString("Enter the customer's name: "));

		if (index != -1) break;
		std::cout << "\nCould not find customer registered under the specified name.";
	}

	customers[index]->printCarsRented();

	while (true) {
		carID = recieveInt("Select one of the above car ID's");
		cin.ignore();

		indexCar = searchCar(carID);

		if (indexCar != -1) break;
		std::cout << "\nCould not find car of specified ID.";
	}

	customers[index]->removeCar(indexCar);
	cars[indexCar]->setPickUp(Date());
	cars[indexCar]->setDropOff(Date());
	cars[indexCar]->setAvailability(true);
}

int Company::streamToInt(std::istringstream &date) {
	string temp;
	date >> temp;
	return stoi(temp);
}

void Company::addCustomer(Customer* newCustomer){
	if (amountCustomers >= 1000) {
		cout << "\nCurrent ammount of customers full. Cannot add anymore customers!";
		return;
	}
	customers[amountCustomers++] = newCustomer;
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
	if (amountCars <= 0) {
		cout << "\nNo Cars in Database";
		return;
	}
	printCar((recieveInt("Input the Rental Car ID")));
	cin.ignore();
}

void Company::printCustomer() {
	if (amountCustomers <= 0){
		cout << "\nNo Customers in Database";
		return;
	}
	printCustomer((recieveInt("Input the Customer ID")));
	cin.ignore();
}

void Company::printCar(int ID) {
	int it = searchCar(ID);
	if (it != -1) {
		cars[it]->print();

		return;
	}

	cout << "\nInvalid ID";
	printCar();
}

void Company::printCustomer(int ID) {
	int it = searchCustomer(ID);
	if (it != -1) {
		customers[it]->print(); //this is meant to print customers not cars
		customers[it]->printCarsRented();
		return;
	}

	cout << "\nInvalid ID";
	printCustomer();
}


void Company::printAllCars() {
	cout << "\nAll Cars Owned by " << name << ":";

	if (amountCars == 0) {
		cout << "\nNo cars currently owned";
		return;
	}

	for (int i(0); i < amountCars; i++) {
		cars[i]->print();
	}
	return;
}

void Company::printAllCustomers() {
	for(int i(0); i < amountCustomers; i++){
		customers[i]->print();
		cout << "\n";
	}
}

void Company::printAvalableCars(){
	for (int i(0); i < amountCars; i++) {
		if (cars[i]->getAvailability()) {
			cars[i]->print();
		}
	}
	return;
}

int Company::searchCustomer(int ID) {
	for (int i(0); i < amountCustomers; i++){
		if (customers[i]->getId() == ID){
			return i;
		}
	}
	return -1;
}

int Company::searchCustomer(string name){
	for (int i(0); i < amountCustomers; i++) {
		if (customers[i]->getName() == name) {
			return i;
		}
	}
	return -1;
}