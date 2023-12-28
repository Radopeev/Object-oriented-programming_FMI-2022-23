#include "DivisibleByExactlyOne.h"


DivisibleByExactlyOne::DivisibleByExactlyOne(Vector<int32_t>& elements,short N) :elements(std::move(elements)),N(N) {

}

bool DivisibleByExactlyOne::operator()(int32_t element) const {
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (elements[i] == 0)
			continue;
		if (element % elements[i] == 0) {
			count++;
		}
	}
	return count != 1 ? false : true;
}

