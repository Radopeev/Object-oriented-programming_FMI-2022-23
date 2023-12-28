#pragma once
#include "Vector.hpp"


class Set
{
public:
	virtual bool contains(int32_t element)const = 0;
	virtual Set* clone()const = 0;
	virtual ~Set() = default;
};


