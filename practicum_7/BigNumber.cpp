#include "BigNumber.h"
#include<iostream>
#pragma warning(disable:4996)

int getNumberLength(long long int num) {
	int count = 0;
	while (num != 0) {
		num /= 10;
		count++;
	}
	return count;
}
void reverse(char* number) {
	int len = strlen(number);
	for (int i = 0; i < len / 2; i++) {
		char temp = number[i];
		number[i] = number[len - i - 1];
		number[len - i - 1] = temp;
	}
}

void BigNumber::copyFrom(const BigNumber& other) {
	number = new char[other.length + 1];
	strcpy(number, other.number);
	length = other.length;
}
void BigNumber::free() {
	delete[] number;
	length = 0;
}
BigNumber::BigNumber() = default;

BigNumber::BigNumber(const char* number) {
	length = strlen(number);
	this->number = new char[length + 1];
	strcpy(this->number, number);
}

BigNumber::BigNumber(long long int num) {
	int numberLength = getNumberLength(num),i=0;
	number = new char[numberLength + 1];
	while (num!=0) {
		long long int curr = num % 10;
		number[i] = curr;
		num /= 10;
		i++;
	}
	reverse(number);
}

BigNumber::BigNumber(const BigNumber& other) {
	copyFrom(other);
}
BigNumber& BigNumber::operator=(const BigNumber& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
BigNumber::~BigNumber() {
	free();
}
size_t BigNumber::getLength()const {
	return length;
}

BigNumber& BigNumber::operator += (const BigNumber& other) {
	int i = length-1, j = other.length-1;
	while(i>=0 && j>=0){
		number[i] += other.number[j];
		number[i] -= 48;
		if (number[i] >=58) {
			number[i] -= 10;
			number[i -1]++;
		}
		i--;
		j--;
	}
	return *this;
}
BigNumber& BigNumber::operator -= (const BigNumber& other) {
	int i = length - 1, j = other.length - 1;
	while (i >= 0 && j >= 0) {
		number[i] += other.number[j];
		number[i] -= 48;
		if (number[i] <=48) {
			number[i] += 10;
			number[i + 1]--;
		}
		i--;
		j--;
	}
	return *this;
}
BigNumber& BigNumber::operator *= (const BigNumber& other) {
	int i = length - 1, j = other.length - 1;
	while (i >= 0 && j >= 0) {
		(int) number[i])*= ((int)other.number[j]);
		if (number[i] >= 58) {
			number[i - 1] = number[i] / 10;
			number[i] %= 10;
		}
		i--;
		j--;
	}
	return *this;
}

bool operator == (const BigNumber& lhs,const BigNumber& rhs) {
	if (lhs.length != rhs.length) {
		return false;
	}
	else {
		for (int i = 0; i < lhs.length; i++) {
			if (lhs.number[i] != rhs.number[i]) {
				return false;
			}
		}
		return true;
	}
}
bool operator != (const BigNumber& lhs, const BigNumber& rhs) {
	if (lhs.length != rhs.length) {
		return true;
	}
	else {
		for (int i = 0; i < lhs.length; i++) {
			if (lhs.number[i] != rhs.number[i]) {
				return true;
			}
		}
		return false;
	}
}
bool operator < (const BigNumber& lhs, const BigNumber& rhs) {
	if (lhs.length < rhs.length) {
		return true;
	}
	else if (lhs.length > rhs.length) {
		return false;
	}
	else {
		for (int i = 0; i < lhs.length; i++) {
			if (lhs.number[i] < rhs.number[i]) {
				return true;
			}
		}
		return false;
	}
}
bool operator > (const BigNumber& lhs, const BigNumber& rhs) {
	if (lhs.length > rhs.length) {
		return true;
	}
	else if(lhs.length<rhs.length){
		return false;
	}
	else {
		for (int i = 0; i < lhs.length; i++) {
			if (lhs.number[i] > rhs.number[i]) {
				return true;
			}
		}
		return false;
	}
}


BigNumber operator + (const BigNumber& lhs, const BigNumber& rhs) {
	BigNumber result(lhs);
	result += rhs;
	return result;
}
BigNumber operator - (const BigNumber& lhs, const BigNumber& rhs) {
	int resultLength = (lhs.getLength() > rhs.getLength() ? lhs.getLength() : rhs.getLength());
	BigNumber result(lhs);
	result -= rhs;
	return result;
}
BigNumber operator * (const BigNumber& lhs, const BigNumber& rhs) {
	BigNumber result(lhs);
	result *= rhs;
	return result;
}