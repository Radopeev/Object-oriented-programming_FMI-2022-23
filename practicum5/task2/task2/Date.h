#pragma once
class Date
{
private:
	const size_t MAX_DAYS[12] = {
		31,28,31,30,31,30,31,31,30,31,30,31
	};
	size_t day;
	size_t month;
	size_t year;
public:
	Date();
	Date(size_t day, size_t month, size_t year);
	void addSomeDays(size_t n);
	void removeSomeDays(size_t n);
	bool isLeapYear();
	size_t daysUntilChristmas();
	size_t daysUntilNewYear();
	size_t dayUntil(const Date& other);
	size_t isLaterThen(const Date& other);
};

