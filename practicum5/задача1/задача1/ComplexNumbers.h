#pragma once
class ComplexNumber
{
private:
	int realPart;
	int complexPart;
public:

	ComplexNumber()  ;

	ComplexNumber(int realPart, int ccomplexPart) ;

	bool isEqual(const ComplexNumber& other)const;

	ComplexNumber add(const ComplexNumber& other)const;

	ComplexNumber multiply(const ComplexNumber& other)const;

	void conjugate();

	ComplexNumber getConjugated();

	void print()const;
};

