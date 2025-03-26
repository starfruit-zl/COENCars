#include <iostream>
#include "Customer.h"
#include "Company.h"

int main()
{
    Company COENCars("COENCars");

    std::cout <<"Welcome to the Car Rental Management System for " << COENCars.getName();
    int selection = 0;;

    while (selection >= 0) {
        std::cout << "\n\nPlease choose one of the following.\n1.Manage Cars\n2.Rent Car\n3.Return Car\n4.List Cars\n5.Find Specific Car\n6.List Customer Database\n7.Find Specific Customer\n8.Exit Interface\n\nEnter your selection: ";
        std::cin >> selection;
        std::cin.ignore();

        switch (selection) {
        case 1:
            std::cout << "\nManaging Cars, please choose one of the following.\n1.Add Car\n2.Remove Car\n3.Cancel\nEnter your selection: ";
            std::cin >> selection;
            std::cin.ignore();
            switch (selection) {
            case 1:
                COENCars.addCar();
                break;
            case 2:
                COENCars.removeCar();
                break;
            case 3:
                continue;
                break;
            }
            break;
        case 2:
            COENCars.rentCar();
            break;
        case 3:
            COENCars.returnCar();
            break;
        case 4:
            COENCars.printAllCars();
            break;
        case 5:
            COENCars.printCar();
            break;
        case 6:
            COENCars.printAllCustomers();
            break;
        case 7:
            COENCars.printCustomer();
            break;
        case 8:
            selection = -1;
            break;
        default:
            std::cout << "\nInvalid Selection! Please try again.";
            continue;
        }
    }

}

