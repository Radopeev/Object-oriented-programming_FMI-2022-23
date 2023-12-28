#pragma once
#include<iostream>
class Predicate {
	public:
	virtual bool operator()(int32_t element)const = 0;
	virtual ~Predicate() = default;
};
