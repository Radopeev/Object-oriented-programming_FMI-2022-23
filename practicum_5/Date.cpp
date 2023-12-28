#include "Date.h"

Date::Date() {
	day = 1;
	month = 1;
	year = 2000;
}
Date::Date(size_t day, size_t month, size_t ye
void addSomeDays(size_t n);
void removeSomeDays(size_t n);
bool isLeapYear();
size_t daysUntilChristmas();
size_t daysUntilNewYear();
size_t dayUntil(const Date& other);
size_t isLaterThen(const Date& other);