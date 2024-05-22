#pragma once
#include "Set.h"
#include "Predicate.h"
#include "Normal.h"
#include "DivisibleByExactlyOne.h"
#include "NotDivisible.h"
#include "SetByCriteria.h"
#include "Union.h"
#include "Intersect.h"
#include "SharedPtr.hpp"
#include "SetCollection.h"
#include"UniquePointer.hpp"
#include <fstream>

class SetFromFile{
private:
	UniquePointer<Set> setFromFile;
	short N=0;
	short T=0;

	void buildSet(std::ifstream& in);
	void ifTisZero(std::ifstream& in);
	void ifTIsOne(std::ifstream& in);
	void ifTIsTwo(std::ifstream& in);
	void ifTIsThree(std::ifstream& in);
	void ifTIsFour(std::ifstream& in);
public:
	SetFromFile(const char* fileName);
	UniquePointer<Set>& getSet() ;
	const UniquePointer<Set>& getSet()const;
};

void readMultipleSets(SetCollection& sets, std::ifstream& in, short N);
void readSetFromFile(Vector<int32_t>& set, std::ifstream& in, short N);