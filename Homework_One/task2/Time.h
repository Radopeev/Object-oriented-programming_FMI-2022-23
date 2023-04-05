#pragma once
#include <iostream>

class Time
{
	size_t seconds; 
	size_t mins;
	size_t hours; 


public:
	Time(); 
	Time(size_t hours, size_t mins, size_t seconds);
	Time(size_t seconds);

	size_t convertToSeconds() const;

	size_t getSeconds() const;
	size_t getMins() const;
	size_t getHours() const;

	void setSeconds(size_t seconds);
	void setMins(size_t mins);
	void setHours(size_t hours);

	int compare(const Time& other) const;
	Time getDiff(const Time& other) const;

	void print() const;
};
