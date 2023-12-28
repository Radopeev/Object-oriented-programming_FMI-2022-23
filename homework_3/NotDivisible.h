#pragma once
#include"Predicate.h"
#include "Vector.hpp"
class NotDivisible:public Predicate
{
	Vector<int32_t> elements;
	short N;
public:
	NotDivisible(Vector<int32_t>& elements, short N);
	bool operator()(int32_t number) const override;
};
