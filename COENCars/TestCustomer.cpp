#include <iostream>
#include "Customer.h"

using namespace std;

void testCustomer(Customer&, string& name, string& address, string& phoneNum);

int main(){
    string testName("Jimmy"), testAddress("45 Lane street"), testPhoneNum("18003825968"), nul({});
    Car* testcar = new LuxuryCar("Honda Civic", false);
    Customer A, B(testName, testAddress, testPhoneNum);
    cout << "\nTesting Null constructor:";
    testCustomer(A, nul, nul, nul);
    A.setName(testName);
    A.setAddress(testAddress);
    A.setPhoneNum(testPhoneNum);
    if (A.getName() != testName)
        cout << "\nsetName function not functioning correctly";
    if (A.getAddress() != testAddress)
        cout << "\nsetAddress function not functioning correctly";
    if (A.getPhoneNum() != testPhoneNum)
        cout << "\nsetPhoneNum function not functioning correctly";
    A.addCar(testcar);
    if (A.getRentedNum() != 1)
        cout << "\naddCar / rentedNum not functioning / incrementing";
    cout << "\nPrinting cars (Should be 1 car)";
    A.printCarsRented();
    A.removeCar(1);
    if (A.getRentedNum() != 0)
        cout << "\nremoveCar / rentedNum not functioning / decrementing";

    cout << "Testing constructor with test data";
    testCustomer(B, testName, testAddress, testPhoneNum);

    delete testcar;
    testcar = nullptr;

    return 0;
}

void testCustomer(Customer& obj, string& name, string& address, string& phoneNum) {
    if (obj.getName() != name)
        cout << "\ngetName / name not inisialised properly";
    if (obj.getAddress() != address)
        cout << "\ngetAddress / Address not inisialised properly";
    if (obj.getPhoneNum() != phoneNum)
        cout << "\ngetPhoneNum / phoneNum not inisialised properly";
}