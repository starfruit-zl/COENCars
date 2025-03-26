#include "Date.h"
#include <string>

using namespace std;

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int Day, int Month, int Year) : day(Day), month(Month), year(Year) {}

int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}
void Date::setDay(int D) {
	day = D;
}
void Date::setMonth(int M) {
	month = M;
}
void Date::setYear(int Y) {
	year = Y;
}

string Date::dateStr(){
	return string(to_string(day) + "/" + to_string(month) + "/" + to_string(year));
}


bool Date::operator==(Date right){
	if (day == right.getDay() && month == right.getMonth() && year == right.getYear())
		return true;
	else
		return false;
}

bool Date::operator>(Date right){
	if (year > right.getYear()) //if the year is greater, otherwise the year is equal to or less than
		return true;
	else if (month > right.getMonth() && year >= right.getYear())
		return true;
	else if (day > right.getDay() && month >= right.getMonth() && year >= right.getYear())
		return true;
	else
		return false;
}

bool Date::operator<(Date right){
	if (year < right.getYear())
		return true;
	else if (month < right.getMonth() && year <= right.getYear())
		return true;
	else if (day < right.getDay() && month <= right.getMonth() && year <= right.getYear())
		return true;
	else
		return false;
}