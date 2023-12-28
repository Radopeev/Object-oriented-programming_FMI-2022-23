#pragma once
#include "Set.h"
#include "Vector.hpp"
#include "SharedPtr.hpp"
#include "SetFromFile.h"
#include "SetCollection.h"

class Intersect :public Set {
	SetCollection sets;
public:
	Intersect(SetCollection& sets);
	Set* clone() const override;
	bool contains(int32_t element)const override;
};


