#include "NotDivisible.h"



NotDivisible::NotDivisible(Vector<int32_t>& elements, short N) : N(N) ,elements(std::move(elements)){
}


bool NotDivisible::operator()(int32_t number) const {
	bool isDivisibleByAllElements = true;
	for (int i = 0; i < N; i++) {
		if (elements[i] == 0)
			continue;
		if (number % elements[i] == 0) {
			isDivisibleByAllElements = false;
		}
	}
	return isDivisibleByAllElements;
}

