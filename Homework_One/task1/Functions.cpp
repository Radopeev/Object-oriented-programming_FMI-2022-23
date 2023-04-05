#include<iostream>
#include<fstream>
#include "Functions.h"
#include "constants.h"

using namespace Messages;
using namespace Commands;

void Functions::left(const char* str, size_t padding, std::ostream& console) {
	console << str;
	for (size_t i = strlen(str); i < padding; i++) {
		console << " ";
	}
}

void Functions::right(const char* str, size_t padding,std::ostream& console) {
	for (size_t i = padding; i >= strlen(str); i--) {
		console << " ";
	}
	console << str;
}

void Functions::center(const char* str, const size_t padding, std::ostream& console) {
	for (size_t i = 0; i < padding/2; ++i) console << " ";
	console << str;
	for (size_t i= strlen(str); i < padding; ++i) console << " ";
}

bool Functions::isValidCharacter(char a) {
	if (a > '!' && a < '}') return true;
	return false;
}

bool Functions::areThereCharactersLeft(const char* s, size_t index) {
	while ((s[index] != '\0')) {
		if (isValidCharacter(s[index])) {
			return true;
		}
		index++;
	}
	return false;
}

char* Functions::removeSpaces(const char* s)
{
	char* result = new char[strlen(s) + 1];
	size_t i = 0, j = 0;
	while (!isValidCharacter(s[i])) {
		i++;
	}
	while (areThereCharactersLeft(s, i)) {

		result[j] = s[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return result;
}

const Alignments& Functions::alignmentChecker(const char* str) {
	bool leftAlignement = false, rightAlignment = false;
	size_t i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ':' && str[i + 1] == '-') {
			leftAlignement = true;
		}
		if (str[i] == '-' && str[i + 1] == ':') {
			rightAlignment = true;
		}
		i++;
	}
	if (leftAlignement && rightAlignment) return Alignments::center;
	else if (rightAlignment) return Alignments::right;
	return Alignments::left;
}