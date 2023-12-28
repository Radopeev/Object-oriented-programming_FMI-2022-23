#include "Label.h"

Label ::Label() {
	MyString location;
	size_t width, height;
	std::cout << "Size :";
	std::cin >> width >> height;
	setSize(width, height);
	std::cout << "Location";
	std::cin >> location;
	setLocation(locationCheck(location));
}
void Label::setDataDialog() {
	std::cout << "Text: ";
	std::cin >> label;
	std::cout << std::endl;
}
Control* Label::clone()const {
	return new Label (*this);
}

