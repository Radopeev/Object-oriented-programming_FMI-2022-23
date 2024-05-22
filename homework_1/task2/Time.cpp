#include "Time.h"

Time::Time(size_t hours, size_t mins, size_t seconds)
{
	setHours(hours);
	setMins(mins);
	setSeconds(seconds);
}

Time::Time() : Time(0, 0, 0)
{}

Time::Time(size_t seconds)
{
	hours = seconds / 3600;
	seconds %= 3600;

	mins = seconds / 60;
	seconds %= 60;

	this->seconds = seconds;
}


size_t Time::getSeconds() const
{
	return seconds;
}
size_t Time::getMins() const
{
	return mins;
}
size_t Time::getHours() const
{
	return hours;
}

void Time::setSeconds(size_t seconds)
{
	if (seconds > 59)
		seconds = 59;
	this->seconds = seconds;
}
void Time::setMins(size_t mins)
{
	if (mins > 59)
		mins = 59;
	this->mins = mins;
}
void Time::setHours(size_t hours)
{
	if (hours > 23)
		hours = 23;
	this->hours = hours;
}

int Time::compare(const Time& other) const
{
	size_t mySeconds = convertToSeconds();
	size_t otherSeconds = other.convertToSeconds();

	if (mySeconds > otherSeconds)
		return 1;
	else if (mySeconds < otherSeconds)
		return -1;
	else
		return 0;
}

Time Time::getDiff(const Time& other) const
{
	size_t mySeconds = convertToSeconds();
	size_t otherSeconds = other.convertToSeconds();

	size_t diff;

	if (mySeconds > otherSeconds)
		diff = mySeconds - otherSeconds;
	else
		diff = otherSeconds - mySeconds;

	return Time(diff);
}


void Time::print() const
{
	if (hours < 10)
		std::cout << 0;
	std::cout << hours<<":";
	if (mins < 10)
		std::cout << 0;
	std::cout << mins << ":";
	if (seconds < 10)
		std::cout << 0;
	std::cout << seconds<<" ";

}

size_t Time::convertToSeconds()const{
	return 3600 * hours + 60 * mins + seconds;
}