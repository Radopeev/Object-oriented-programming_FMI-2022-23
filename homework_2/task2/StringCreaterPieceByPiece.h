#pragma once
#include"StringPiece.h"
#include"MyString.h"
class StringCreaterPieceByPiece
{
private:
	StringPiece** pieces;
	size_t count;
	size_t capacity;

	void resize();
	void free();
	void copyFrom(const StringCreaterPieceByPiece& other);
public:
	StringCreaterPieceByPiece(size_t staringCapacity);
	StringCreaterPieceByPiece(const StringCreaterPieceByPiece& other);
	StringCreaterPieceByPiece& operator=(const StringCreaterPieceByPiece& other);
	~StringCreaterPieceByPiece();
	void addPiece(const char* data);
	void addPiece();
	StringPiece& operator[](size_t index)const;
	StringPiece& operator[](size_t index);
	void swapPieces(size_t indexOne, size_t indexTwo);
	void removePiece(size_t index);
	void addPieceByIndex(const char* data, size_t index);
	size_t lengthOfString()const;
	MyString getString()const;
};

