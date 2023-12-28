#include "CheckBox.h"

CheckBox::CheckBox() {
	MyString location;
	size_t width, height;
	std::cout << "Size :";
	std::cin >> width >> height;
	Control::setSize(width, height);
	std::cout << "Location";
	std::cin >> location;
	Control::setLocation(locationCheck(location));
}
void CheckBox::setDataDialog() {
	std::cout << "Text: ";
	std::cin >> text;
	std::cout << "State (1 or 0): ";
	std::cin >> state;
	std::cout << std::endl;
}
Control* CheckBox::clone()const{
	return new CheckBox(*this);
}