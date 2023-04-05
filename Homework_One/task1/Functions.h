#pragma once
#include "Alignments.h"
#include "Table.h" 

namespace Functions {
	void left(const char* str, size_t padding, std::ostream& myFile);
	void right(const char* str, size_t padding, std::ostream& myFile);
	void center(const char* str, size_t padding, std::ostream& myFile);
	bool isValidCharacter(char a);
	bool areThereCharactersLeft(const char* str, size_t index);
	char* removeSpaces(const char* s);
	const Alignments& alignmentChecker(const char* str);
}