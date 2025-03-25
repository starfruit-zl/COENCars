#pragma once
#include <string>
#include <iostream>

using namespace std;

#ifndef DATE
#define DATE

class Date {
private:
	int day, month, year;
	
public:
	Date();
	Date(int, int, int);
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	string dateStr();

	bool operator==(Date);
	bool operator>(Date);
	bool operator<(Date);
};

#endif //DATE
