#include<iostream>
#include "ComplexNumbers.h"
ComplexNumber::ComplexNumber() {
	realPart = 0;
	complexPart = 0;
}

ComplexNumber::ComplexNumber(int realPart, int complexPart) {
	this->realPart = realPart;
	this->complexPart = complexPart;
}

bool ComplexNumber::isEqual(const ComplexNumber& other)const {
	return this->realPart==other.realPart && this->complexPart==other.complexPart;
}

ComplexNumber ComplexNumber::add(const ComplexNumber& other) const {
	return ComplexNumber(this->realPart + other.realPart, this->complexPart + other.complexPart);
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& other)const {
	return ComplexNumber((this->realPart * other.realPart) - (this->complexPart * other.complexPart), (this->realPart * other.complexPart) + (this->complexPart * other.realPart));
}

void ComplexNumber::conjugate() {
	this->complexPart=this->complexPart * (-1);
}

ComplexNumber ComplexNumber::getConjugated() {
 ComplexNumber::conjugate();
 return (*this);
}

void ComplexNumber::print()const {
	if (this->complexPart > 0) {
		std::cout << this->realPart<<"+" << this->complexPart << "i" << std::endl;
	}
	else if (this->realPart == 0) {
		std::cout << this->realPart << std::endl;
	}
	else {
		std::cout << this->realPart<< this->complexPart << "i" << std::endl;
	}
}