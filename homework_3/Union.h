#pragma once
#include "Set.h"
#include "Vector.hpp"
#include "SharedPtr.hpp"
#include "SetCollection.h"
class Union:public Set
{
	SetCollection  sets;
public:
	Union(SetCollection&  sets);
	Set* clone() const override;
	bool contains(int32_t element)const override;
};

