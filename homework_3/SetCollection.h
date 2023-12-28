#pragma once
#include "Set.h"
#include "SharedPtr.hpp"
#include "UniquePointer.hpp"

class SetCollection {
private:
	Set** sets = nullptr;
	size_t size;
	size_t capacity;

	void resize();
public:
	const Set* operator[](size_t index)const;
	Set* operator[](size_t index);
	size_t getSize()const;
	void addSet(UniquePointer<Set>& newset);
	void addSet(const SharedPtr<Set>& newset);
	void addSet(Set* newset);
	SetCollection();
	SetCollection(const SetCollection& other);
	SetCollection(SetCollection&& other) noexcept;
	SetCollection& operator=(const SetCollection& other);
	SetCollection& operator=(SetCollection&& other) noexcept;
	~SetCollection();

private:
	void move(SetCollection&& other);
	void copyFrom(const SetCollection& other);
	void free();
};


