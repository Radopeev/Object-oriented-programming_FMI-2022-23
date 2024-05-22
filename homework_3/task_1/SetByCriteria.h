#pragma once
#include "Set.h"
#include "Predicate.h"
#include "Vector.hpp"
#include "DivisibleByExactlyOne.h"
#include "NotDivisible.h"
#include "Normal.h"
#include "SharedPtr.hpp"

class SetByCriteria :public Set {
	SharedPtr<Predicate> predicate;
public:
	SetByCriteria(const SharedPtr<Predicate>& predicate);
	Set* clone()const override;
	bool contains(int32_t element)const override;
};

