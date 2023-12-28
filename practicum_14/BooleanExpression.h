#pragma once
#include "StringView.h"
#include "MyString.h"

namespace {
	const char AND = '^';
	const char OR = 'v';
	const char IMPL = '>'; //=>
	const char IFF = '='; // <=>
	const char XOR = '+';
	const char NEG = '!';
}

bool isOperator(char ch);

class BooleanInterpretator {
	bool characters[26];
public:
	void setValue(char value);
	bool getValue(char value)const;

};

class BooleanExpression
{
public:
	bool variables[26]{ false };
	size_t countVars = 0;
	virtual BooleanExpression* clone()const = 0;
	virtual bool eval(const BooleanInterpretator& interpretator)const = 0;
	virtual ~BooleanExpression()=default;
};

class Varialble :public BooleanExpression
{
	char ch;
public:
	Varialble(char ch);
	BooleanExpression* clone()const override;
	bool eval(const BooleanInterpretator& interpretator) const override;
};

class UnaryExpression : public BooleanExpression
{
	char operand;
	BooleanExpression* expr;
public:
	UnaryExpression(char opearan, BooleanExpression* expr);
	bool eval(const BooleanInterpretator& interpretator)const override;
	BooleanExpression* clone()const override;
	~UnaryExpression();
};
class BinaryOperations :public BooleanExpression
{
	BooleanExpression* left;
	BooleanExpression* right;
	char operand;
public:
	BinaryOperations(BooleanExpression* left, BooleanExpression* right, char operand);
	BinaryOperations* clone()const override;
	bool eval(const BooleanInterpretator& interpretator)const override;
	~BinaryOperations();
};

class BoolCalculator {
	BooleanExpression* expr;

	void copyFrom(const BoolCalculator& other);
	void free();
public:
	BoolCalculator(const  MyString& expression);
	BoolCalculator(const BoolCalculator& other);
	BoolCalculator& operator=(const BoolCalculator& other);
	~BoolCalculator();

	bool isTautology()const;
	bool isContradiction()const;
	friend BooleanExpression* parse(const StringView& expr);
};

BooleanExpression* parse(const StringView& expr);
