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
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	string dateStr();

	bool operator==(const Date&) const;
	bool operator>(const Date&) const;
	bool operator<(const Date&) const;
};

#endif //DATE
