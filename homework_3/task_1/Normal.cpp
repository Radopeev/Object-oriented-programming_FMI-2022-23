#include "Normal.h"

Normal::Normal(Vector<int32_t>& elements, short N): elements(std::move(elements)),N(N) {

}
bool Normal::operator()(int32_t element) const {
	bool isElementInSet = false;
	for (int i = 0; i < N; i++) {
		if (elements[i] == element)
			isElementInSet = true;
	}
	return isElementInSet;
}