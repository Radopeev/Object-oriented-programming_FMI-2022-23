#include "RadioButton.h"

RadioButton::RadioButton() {

	MyString location;
	size_t width, height;
	std::cout << "Size :";
	std::cin >> width >> height;
	setSize(width, height);
	std::cout << "Location";
	std::cin >> location;
	setLocation(locationCheck(location));
}
void RadioButton::setDataDialog() {
	std::cout << "Options Count: ";
	std::cin >> optionCount;
	this->options.resize(optionCount);
	this->states.resize(optionCount);
	for (size_t i = 0; i < optionCount; i++) {
		std::cout << "Option: ";
		std::cin >> options[i];
		std::cout << "State: ";
		std::cin >> states[i];
	}
}
Control* RadioButton::clone()const{
	return new RadioButton(*this);
}
