#include "BooleanExpression.h"

bool isOperator(char ch)
{
	return ch == AND || ch == OR || ch == IFF || ch == IMPL || ch == XOR || ch == NEG;
}

bool BooleanInterpretator::getValue(char value)const {
	return characters[value - 'A'];
}

void BooleanInterpretator::setValue(char value) {
	characters[value - 'A'] = true;
}

//------------------------------------------------
Varialble::Varialble(char ch) :ch(ch) {
	variables[ch - 'A'];
	countVars++;
}
BooleanExpression* Varialble::clone()const {
	return new Varialble(ch);
}
bool Varialble::eval(const BooleanInterpretator& interpretator) const {
	return interpretator.getValue(ch);
}
//---------------------------------------------
BooleanExpression* UnaryExpression::clone()const {
	return new UnaryExpression(operand, expr->clone());
}

UnaryExpression::UnaryExpression(char operand, BooleanExpression* expr) {
	if (operand != '!') {
		return;
	}
	this->expr = expr;
}
bool UnaryExpression::eval(const BooleanInterpretator& interpretator)const {
	return true;
}
UnaryExpression::~UnaryExpression() {
	delete expr;
}
//---------------------------------------------
BinaryOperations::BinaryOperations(BooleanExpression* left, BooleanExpression* right, char operand) {
	this->left = left;
	this->right = right;

}
BinaryOperations* BinaryOperations::clone()const {
	return new BinaryOperations(left->clone(), right->clone(), operand);
}
bool BinaryOperations::eval(const BooleanInterpretator& interpretator)const  {
	switch (operand) {
		case AND:return left->eval(interpretator) && right->eval(interpretator);
		case OR:return left->eval(interpretator) || right->eval(interpretator);
		case IFF: {bool first = left->eval(interpretator); bool second = right->eval(interpretator); return first == second; }
		case IMPL:return !left->eval(interpretator) || right->eval(interpretator);
		case XOR: {bool first = left->eval(interpretator); bool second = right->eval(interpretator); return first != second; }
		default: return false; break;
	}
}
BinaryOperations::~BinaryOperations() {
	delete left;
	delete right;
}
//---------------------------------------------

void BoolCalculator::copyFrom(const BoolCalculator& other){
	expr = other.expr->clone();
}
void BoolCalculator::free() {
	delete expr;
}
BoolCalculator(const MyString& expression) {
	expr = parse(expression);
}
	BoolCalculator(const BoolCalculator& other);
	BoolCalculator& operator=(const BoolCalculator& other);
	~BoolCalculator();

	bool isTautology()const;
	bool isContradiction()const;

BooleanExpression* parse(const StringView& expr) {
	if (expr.length() == 1) {
		return new Variable(expr[0]);
	}
	StringView strWithoutBrackets = expr.substr(1, expr.length()-2);
	for (int i = 0; i < strWithoutBrackets.length(); i++) {

	}
}


