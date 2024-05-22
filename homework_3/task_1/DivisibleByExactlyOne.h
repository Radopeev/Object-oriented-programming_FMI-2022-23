#pragma once
#include "Predicate.h"
#include "Vector.hpp"

class DivisibleByExactlyOne:public Predicate
{
	Vector<int32_t> elements;
	short N;
public:
	DivisibleByExactlyOne(Vector<int32_t>& elements,short N);
	bool operator()(int32_t element) const override;
};
