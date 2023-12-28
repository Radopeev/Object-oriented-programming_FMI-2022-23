#pragma once
#include "MyString.h"
enum class Location {
	upperLeft,
	upperCenter,
	upperRight,
	centerLeft,
	centerCenter,
	centerRight,
	lowerLeft,
	lowerCenter,
	lowerRight,
};
Location locationCheck(const MyString& location);
struct Size
{
	size_t width;
	size_t height;
};
class Control
{
protected:
	Size size;
	Location location;
public:
	void setSize(size_t width, size_t height);
	void setLocation(Location location);
	virtual Control* clone()const = 0;
	virtual void setDataDialog() = 0;
	virtual ~Control();
};

