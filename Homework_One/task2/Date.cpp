#include "Date.h"

Date::Date() {
	setYear(0);
	setMonth(0);
	setDay(0);
}

Date::Date(unsigned day, unsigned month, unsigned year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

unsigned Date::getDay() const
{
	return day;
}

unsigned Date::getMonth() const
{
	return month;
}

unsigned Date::getYear() const
{
	return year;
}

void Date::setYear(unsigned year)
{
	if (year == this->year)
		return;
	this->year = year;
	if (isLeapYear())
		MAX_DAYS[1] = 29;
	else
		MAX_DAYS[1] = 28;
	setDay(getDay());

	isModified = true;

}

void Date::setDay(unsigned day)
{
	if (day == this->day)
		return;

	if (day == 0 || day > MAX_DAYS[month - 1])
		day = 1;
	this->day = day;

	isModified = true;
}

void Date::setMonth(unsigned month)
{
	if (month == this->month)
		return;

	if (month == 0 || month > 12)
		month = 1;
	this->month = month;
	setDay(getDay());

	isModified = true;
}

int Date::compare(const Date& other) const
{
	if (year > other.year) {
		return 1;
	}
	else if (year < other.year) {
		return -1;
	}
	if (month > other.month) {
		return 1;
	}
	else if (month < other.month) {
		return -1;
	}
	if (day > other.day) {
		return 1;
	}
	else if (day < other.day) {
		return -1;
	}
	return 0;
}

void Date::print() const
{
	std::cout << day << "." << month << "." << year << std::endl;
}


bool Date::isLeapYear() const
{
	if (year <= 1916)
		return year % 4 == 0;
	else
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}