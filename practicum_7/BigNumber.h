#pragma once

class BigNumber
{
private:
	char* number;
	size_t length;
	
	void copyFrom(const BigNumber& other);
	void free();
public:
	BigNumber();
	BigNumber(const char* number);
	BigNumber(long long int);
	BigNumber(const BigNumber& other);
	BigNumber& operator=(const BigNumber& other);
	~BigNumber();

	size_t getLength()const;
	BigNumber& operator += (const BigNumber& other);
	BigNumber& operator -= (const BigNumber& other);
	BigNumber& operator *= (const BigNumber& other);

	friend bool operator ==  (const BigNumber& lhs, const BigNumber& rhs);
	friend bool operator !=  (const BigNumber& lhs, const BigNumber& rhs);
	friend bool operator <  (const BigNumber& lhs, const BigNumber& rhs);
	friend bool operator >  (const BigNumber& lhs, const BigNumber& rhs);
};


BigNumber operator + (const BigNumber& lhs,const BigNumber& rhs);
BigNumber operator - (const BigNumber& lhs, const BigNumber& rhs);
BigNumber operator * (const BigNumber& lhs, const BigNumber& rhs);

