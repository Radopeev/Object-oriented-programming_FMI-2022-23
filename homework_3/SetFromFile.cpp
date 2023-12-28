#include "SetFromFile.h"
#include "UniquePointer.hpp"
#include<utility>
namespace {
	const char ERROR_WITH_FILE[] = "Error with file";
	const char INVALID_ARGUMENT[] = "Invalid arguemnt";
	const char FILE_NAME[] = "set.dat";
	const size_t MAX_SIZE_OF_N = 32;
}

void readSetFromFile(Vector<int32_t>& set,std::ifstream& in,short N) {
	if (in.is_open()) {
		for (int i = 0; i < N; i++) {
			int currNum;
			in.read((char*)&currNum, sizeof(int));
			set.pushBack(currNum);
		}
	}
	else
		throw std::runtime_error(ERROR_WITH_FILE);
}
void readMultipleSets(SetCollection&  sets,std::ifstream& in,short N) {
	for (int i = 0; i < N; i++) {
		int length;
		in.read((char*)&length, sizeof(int));
		char* buffer = new char[length + 1];
		in.read(buffer, length);
		buffer[length] = '\0';
		in.get();
		SetFromFile currSetFromFile(buffer);
		sets.addSet(currSetFromFile.getSet());
		delete[] buffer;
	}
}

SetFromFile::SetFromFile(const char* fileName){
	std::ifstream in(fileName, std::ios::binary);
	in.read((char*)&N, sizeof(short));
	if (MAX_SIZE_OF_N > 32)
		throw std::runtime_error(INVALID_ARGUMENT);
	in.read((char*)&T, sizeof(short));
	buildSet(in);
}

void SetFromFile::buildSet(std::ifstream& in) {
	switch (T) {
	case 0:ifTisZero(in); break;
	case 1:ifTIsOne(in); break;
	case 2:ifTIsTwo(in); break;
	case 3:ifTIsThree(in); break;
	case 4:ifTIsFour(in); break;
		default: throw std::invalid_argument(INVALID_ARGUMENT);
	}
}


void SetFromFile::ifTisZero(std::ifstream& in) {
	Vector<int32_t> set;
	readSetFromFile(set, in,N);
	SharedPtr<Predicate> pred(new Normal(set,N));
	setFromFile= new SetByCriteria(pred);
}

void SetFromFile::ifTIsOne(std::ifstream& in) {
	Vector<int32_t> set;
	readSetFromFile(set, in,N);
	SharedPtr<Predicate> pred(new NotDivisible(set, N));
	setFromFile= new SetByCriteria(pred);
}


void SetFromFile::ifTIsTwo(std::ifstream& in) {
	Vector<int32_t> set;
	readSetFromFile(set, in,N);
	SharedPtr<Predicate> pred(new DivisibleByExactlyOne(set, N));
	setFromFile= new SetByCriteria(pred);
}

void SetFromFile::ifTIsThree(std::ifstream& in) {
	SetCollection sets;
	readMultipleSets(sets, in, N);
	setFromFile = new Union(sets);
}

void SetFromFile::ifTIsFour(std::ifstream& in) {
	SetCollection sets;
	readMultipleSets(sets, in, N);
	setFromFile = new Intersect(sets);
}
const UniquePointer<Set>& SetFromFile::getSet() const {
	return setFromFile;
}
UniquePointer<Set>& SetFromFile::getSet() {
	return setFromFile;
}
