#include "StringCreaterPieceByPiece.h"

void StringCreaterPieceByPiece::resize() {
	capacity *= GROWTH_FACTOR;
	StringPiece** temp = new StringPiece*[capacity];
	for (size_t i = 0; i < count; i++) {
		temp[i] = pieces[i];
	}
	delete[] pieces;
	pieces = temp;

}
StringCreaterPieceByPiece::StringCreaterPieceByPiece(size_t startingCapacity) {
	count = 0;
	capacity = startingCapacity;
	pieces = new StringPiece* [capacity];
}
StringCreaterPieceByPiece::StringCreaterPieceByPiece(const StringCreaterPieceByPiece& other) {
	copyFrom(other);
}
StringCreaterPieceByPiece& StringCreaterPieceByPiece::operator=(const StringCreaterPieceByPiece& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
StringCreaterPieceByPiece::~StringCreaterPieceByPiece() {
	free();
}
void StringCreaterPieceByPiece::free() {
	for (size_t i = 0; i < count; i++) {
		delete pieces[i];
	}
	delete[] pieces;
	count = capacity = 0;
}
void StringCreaterPieceByPiece::copyFrom(const StringCreaterPieceByPiece& other) {
	capacity = other.capacity;
	count = other.count;
	pieces = new StringPiece*[capacity];

	for (size_t i = 0; i < count; i++) {
		pieces[i] = new StringPiece(*(other.pieces[i]));
	}
}
void StringCreaterPieceByPiece::addPiece(const char* data) {
	if (count >= capacity)
		resize();
	pieces[count++] = new StringPiece(data);
}
void StringCreaterPieceByPiece::addPiece() {
	if (count >= capacity)
		resize();
	pieces[count++] = new StringPiece("");
}
void StringCreaterPieceByPiece::swapPieces(size_t indexOne, size_t indexTwo) {
	if (indexOne > count || indexTwo > count)
		throw std::out_of_range(INVALID_INDEX);
	StringPiece* temp = pieces[indexOne];
	pieces[indexOne] = pieces[indexTwo];
	pieces[indexTwo] = temp;
}
void StringCreaterPieceByPiece::removePiece(size_t index) {
	if (index > count)
		throw std::out_of_range(INVALID_INDEX);
	delete pieces[index];
	pieces[index] = pieces[count - 1];
	pieces[--count] = nullptr;
}
void StringCreaterPieceByPiece::addPieceByIndex(const char* data, size_t index) {
	if (index > count)
		throw std::out_of_range(INVALID_INDEX);
	if (count >= capacity)
		resize();
	pieces[index] = new StringPiece(data);
}
size_t StringCreaterPieceByPiece::lengthOfString()const {
	size_t length = 0;
	for (size_t i = 0; i < count; i++) {
		length += pieces[i]->getSize();
	}
	return length;
}
const StringPiece& StringCreaterPieceByPiece::operator[](size_t index) const{
	return *pieces[index];
}
StringPiece& StringCreaterPieceByPiece::operator[](size_t index) {
	return *pieces[index];
}
MyString StringCreaterPieceByPiece::getString()const {
	MyString result;
	for (size_t i = 0; i < count; i++) {
		if (i == count - 1 && pieces[i] == nullptr)
			break;
		if (pieces[i] == nullptr) {
			result += TWENTY_SPACES;
			continue;
		}
		MyString currPiece = pieces[i]->getData();
		result += currPiece;
	}
	return result;
}