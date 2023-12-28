#include "Controls.h"

Location locationCheck(const MyString& location){
if (location == "upperLeft")
return Location::upperLeft;
if (location == "upperCenter")
return Location::upperCenter;
if (location == "upperRight")
return Location::upperRight;
if (location == "centerLeft")
return Location::centerLeft;
if (location == "center")
return Location::centerCenter;
if (location == "centerRight")
return Location::centerRight;
if (location == "lowerLeft")
return Location::lowerLeft;
if (location == "lowerCenter")
return Location::lowerCenter;
if (location == "lowerRight")
return Location::lowerRight;
}
void Control::setSize(size_t width, size_t height) {
	size.width = width;
	size.height = height;
}
void Control::setLocation(Location location) {
	this->location = location;
}