#include "Union.h"


Union::Union(SetCollection& sets) :sets(std::move(sets)){
}

Set* Union::clone() const {
	return new Union(*this);
}
 bool Union::contains(int32_t element)const {
	 for (int i = 0; i < sets.getSize(); i++) {
		 if (sets[i]->contains(element))
			 return true;
	}
	 return false;
}