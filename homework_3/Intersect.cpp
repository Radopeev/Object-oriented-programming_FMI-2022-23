#include "Intersect.h"



Intersect::Intersect(SetCollection&  sets) :sets(std::move(sets)){

}

bool Intersect::contains(int32_t element)const {
	for (int i = 0; i < sets.getSize(); i++) {
		if(!sets[i]->contains(element))
			return false;
	}
	return true;
}

Set* Intersect::clone()const {
	return new Intersect(*this);
}


