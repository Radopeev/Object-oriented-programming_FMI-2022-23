#pragma once
#include "Predicate.h"
#include "Vector.hpp" 
class Normal: public Predicate
{
	Vector<int32_t> elements;
	short N;
public:
	Normal(Vector<int32_t>& elements, short N);
	bool operator()(int32_t element) const override;
};

