#include "SetByCriteria.h"

SetByCriteria::SetByCriteria(const SharedPtr<Predicate>& predicate) :predicate(predicate){
}

Set* SetByCriteria::clone()const {
	return new SetByCriteria(*this);
}
bool SetByCriteria::contains(int32_t element)const  {
	return predicate->operator()(element);
}

