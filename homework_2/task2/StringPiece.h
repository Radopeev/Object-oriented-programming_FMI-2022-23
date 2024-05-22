#pragma once
#include "Erros.h"
#include "GlobalConstants.h"
#include "MyString.h"
class StringPiece
{
private:
	char data[MAX_SIZE]{};
	size_t begin;
	size_t end;
	void convertDataAfterLeftConcatenations();
public:
	StringPiece(const char* data);
	size_t getSize() const;
	MyString getData()const;
	void setData(const char* data);
	friend void operator>>(const char* other,StringPiece& piece);
	friend void operator<<(StringPiece& piece,const char* other);
	friend void operator>>(size_t number, StringPiece& piece);
	friend void operator<<(StringPiece& piece, size_t number);
	void removeSymbolsAtTheBeginning(size_t index);
	void removeSymbolsAtTheEnd(size_t index);
	void removeSymbolAtIndex(size_t index);
	static const char* convertNumberToCharArray(size_t number);
};

void operator<<(StringPiece& piece, size_t number);
void operator>>(size_t number, StringPiece& piece);
void operator>>(const char* other,StringPiece& piece);
void operator<<(StringPiece& piece,const  char* other);