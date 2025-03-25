#include <iostream>
#include "Customer.h"
#include "Company.h"

int main()
{
    Company COENCars("COENCars");

    std::cout <<"Welcome to the Car Rental Management System for " << COENCars.getName();
    int selection = 0;;

    while (selection >= 0) {
        std::cout << "\n\nPlease choose one of the following.\n1.Manage Cars\n2.Rent Cars\n3.List Cars\n4.Find Specific Car\n5.List Customer Database\n6.Find Specific Customer\n7.Exit Interface\n\nEnter your selection: ";
        std::cin >> selection;

        switch (selection) {
        case 1:
            std::cout << "\nManaging Cars, please choose one of the following.\n1.Add Car\n2.Remove Car\n3.Cancel";
            std::cin >> selection;

            switch (selection) {
            case 1:
                COENCars.addCar();
                break;
            case 2:
                COENCars.removeCar();
                break;
            case 3:
                continue;
            }
            break;
        case 2:
            break;
        case 3:
            COENCars.printAllCars();
            break;
        case 4:
            COENCars.printCar();
            break;
        case 5:
            //list customers.
            break;
        case 6:
            //list customers.
            break;
        case 7:
            selection = -1;
            break;
        }






    }
}

