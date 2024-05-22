#include "SetCollection.h"
#include "SharedPtr.hpp"
#include <utility>
#include <exception>

SetCollection::SetCollection() : size(0), capacity(4) {
	sets = new Set * [capacity];
}

SetCollection::SetCollection(const SetCollection& other) {
	copyFrom(other);
}

SetCollection::SetCollection(SetCollection&& other) noexcept {
	move(std::move(other));
}

SetCollection& SetCollection::operator=(const SetCollection& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

SetCollection& SetCollection::operator=(SetCollection&& other) noexcept {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

SetCollection::~SetCollection() {
	free();
}

void SetCollection::resize() {
	Set** temp = new Set * [capacity *= 2];
	for (size_t i = 0; i < size; i++) {
		temp[i] = sets[i];
	}
	delete[] sets;
	sets = temp;
}

size_t SetCollection::getSize()const{
	return size;
}
const Set* SetCollection::operator[](size_t index)const {
	return sets[index];
}

Set* SetCollection::operator[](size_t index) {
	return sets[index];
}
void SetCollection::addSet(UniquePointer<Set>& newSet) {
	if (size == capacity) {
		resize();
	}

	sets[size++] = newSet.release();
}

void SetCollection::addSet(const SharedPtr<Set>& newSet) {
	if (size == capacity) {
		resize();
	}

	sets[size++] = newSet.operator->();
}

void SetCollection::addSet(Set* newSet) {
	if (size == capacity) {
		resize();
	}

	sets[size++] = newSet->clone();
}

void SetCollection::move(SetCollection&& other) {
	sets = other.sets;
	size = other.size;
	capacity = other.capacity;
	other.sets = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void SetCollection::copyFrom(const SetCollection& other) {
	size = other.size;
	capacity = other.capacity;

	sets = new Set * [capacity];
	for (size_t i = 0; i < size; i++) {
		sets[i] = other.sets[i]->clone();
	}
}

void SetCollection::free() {
	for (size_t i = 0; i < size; i++) {
		delete sets[i];
	}

	delete[] sets;
	sets = nullptr;
}