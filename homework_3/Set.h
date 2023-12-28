#pragma once
#include"Collection.h"


class Set  
{
protected:
	int* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void free();
	void copyFrom(const Set& other);
	void moveFrom(Set&& other);

	void resize(size_t);
public:
	Set();
	Set(const Set& other);
	Set(Set&& other);
	Set& operator=(const Set& other);
	Set& operator=(Set&& other);
	virtual ~Set();
	
	size_t getSize()const;
	virtual void addElement(int element) = 0;
	virtual void removeElement(int element) = 0;
	virtual bool contains(int element)const = 0;
};