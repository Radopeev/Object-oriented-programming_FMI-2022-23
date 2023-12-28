#include "Set.h"
#include<utility> 

size_t Set::getSize()const {
	return size;
}
void Set::free()
{
	delete[] data;
}

void Set::copyFrom(const Set& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new int[capacity];

	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

void Set::moveFrom(Set&& other)
{
	data = other.data;
	other.data = nullptr;

	other.size = other.capacity = 0;
}

Set::Set(Set&& other)
{
	moveFrom(std::move(other));
}

Set& Set::operator=(Set&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Set::resize(size_t nCap)
{
	int* newData = new int[nCap];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = nCap;
}

Set::Set()
{
	size = 0;
	capacity = 8;

	data = new int[capacity];
}

Set::Set(const Set& other)
{
	copyFrom(other);
}

Set& Set::operator=(const Set& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Set::~Set()
{
	free();
}