#include "StringPiece.h"
#include<iostream>
#pragma warning(disable:4996)
StringPiece::StringPiece(const char* data){
	setData(data);
}
void StringPiece::convertDataAfterLeftConcatenations() {
	char copyData[16]{};
	size_t copyDataIndex = 0;
	for (size_t i = begin; i < end; i++) {
		copyData[copyDataIndex] = data[i];
		copyDataIndex++;
	}
	for (size_t i = 0; i < begin; i++) {
		copyData[copyDataIndex] = data[i];
		copyDataIndex++;
	}
	for (size_t k = 0; k < end; k++) {
			data[k] = copyData[k];
	}
	begin = 0;
}
MyString StringPiece::getData()const {
	MyString result((end-begin)+1);
	size_t stringIndex = 0;
	for (size_t i = begin; i < end; i++) {
		result[stringIndex] = data[i];
		stringIndex++;
	}
	result[stringIndex] = '\0';
	return result;
}

void StringPiece::setData(const char* data) {
	begin = 0;
	end = strlen(data);
	if (end > 16)
		throw std::length_error(TOO_LONG_STRING_IN_CONSTRUCTOR);
	for (size_t i = begin; i < end; i++) {
		this->data[i] = data[i];
	}
}
size_t StringPiece::getSize() const {
	return end - begin;
}
void operator>>(const char* str,StringPiece& piece) {
	size_t strLen = strlen(str);
	piece.begin += piece.end;
	piece.end += strLen;
	if (piece.end > 16)
		throw std::length_error(TOO_LONG_STRING_AFTER_CONCATENATIONS);
	for (size_t i = piece.begin,j=0; i < piece.end; i++,j++) {
		piece.data[i] = str[j];
	}
	piece.convertDataAfterLeftConcatenations();
}
void operator<<(StringPiece& piece,const char* str) {
	size_t strLen = strlen(str);
	if (piece.end > 16)
		throw std::length_error(TOO_LONG_STRING_AFTER_CONCATENATIONS);
	for (size_t i = piece.end, j = 0; i < strLen; i++, j++) {
		piece.data[i] = str[j];
	}
	piece.end += strLen;
}

void operator>>(size_t number, StringPiece& piece)
{
	const char* numberToChar = piece.convertNumberToCharArray(number);
	numberToChar >> piece;
	delete[] numberToChar;
}

void operator<<(StringPiece& piece, size_t number) {
	const char* numberToChar = piece.convertNumberToCharArray(number);
	piece<<numberToChar;
	delete[] numberToChar;
}
void StringPiece::removeSymbolsAtTheBeginning(size_t index) {
	if (index > MAX_SIZE)
		throw std::out_of_range(INVALID_INDEX);
	begin += index;
}
void StringPiece::removeSymbolsAtTheEnd(size_t index) {
	if (index > MAX_SIZE)
		throw std::out_of_range(INVALID_INDEX);
	end -= index;
}
void StringPiece::removeSymbolAtIndex(size_t index) {
	if (index > MAX_SIZE)
		throw std::out_of_range(INVALID_INDEX);
	data[index] = ' ';
}
const char* StringPiece::convertNumberToCharArray(size_t number) {
	size_t i = 0, k = 0, numberArray[MAX_SIZE];
	char* numberToCharArray=new char[MAX_SIZE];
	while (number != 0) {
		numberArray[i] = number % 10;
		number /= 10;
		i++;
	}
	for (int j = i - 1; j >= 0; k++, j--) {
		numberToCharArray[k] = numberArray[j] + '0';
	}
	numberToCharArray[i] = '\0';
	return numberToCharArray;
}