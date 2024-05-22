#pragma once
#include <iostream>
#include <fstream>


template<class T>
class Vector {
private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity;

	void assertIndex(size_t index) const;
	void upsizeIfNeeded();
	void downsizeIfNeeded();
public:
	void resize(size_t newCapacity);
	Vector();
	Vector(size_t capacity);
	Vector(const Vector<T>& other);
	Vector(Vector<T>&& other);
	Vector<T>& operator=(const Vector<T>& other);
	Vector<T>& operator=(Vector<T>&& other);
	~Vector();

	size_t getSize() const;
	size_t getCapacity() const;

	void pushBack(const T& element);
	void pushBack(T&& element);
	void pushAt(const T& element, size_t index);
	void pushAt(T&& element, size_t index);
	T popBack();
	T popAt(size_t index);

	bool empty() const;
	void clear();
	void shrinkToFit();

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

private:
	void move(Vector<T>&& other);
	void copyFrom(const Vector<T>& other);
	void free();
};

namespace {
	const short INITIAL_CAPACITY = 4;
	const short RESIZE_COEF = 2; 
}

template<class T>
Vector<T>::Vector() : Vector(INITIAL_CAPACITY) { }

template<class T>
Vector<T>::Vector(size_t capacity) : capacity(capacity) {
	data = new T[capacity];
}

template<class T>
Vector<T>::Vector(const Vector& other) {
	copyFrom(other);
}

template<class T>
Vector<T>::Vector(Vector&& other) {
	move(std::move(other));
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {

	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

template<class T>
Vector<T>::~Vector() {
	free();
}

template<class T>
void Vector<T>::assertIndex(size_t index) const {
	if (index >= capacity) {
		throw std::exception("Out of range");
	}
}

template<class T>
void Vector<T>::upsizeIfNeeded() {
	if (size == capacity) {
		resize(capacity * RESIZE_COEF);
	}
}

template<class T>
void Vector<T>::downsizeIfNeeded() {
	if (size * RESIZE_COEF * RESIZE_COEF <= capacity) {
		resize(capacity / RESIZE_COEF);
	}
}
template<class T>
void Vector<T>::resize(size_t newCapacity) {
	if (newCapacity == 0) {
		return;
	}
	capacity = newCapacity;
	T* temp = new T[capacity];

	if (size > newCapacity) {
		size = newCapacity;
	}

	for (size_t i = 0; i < size; i++) {
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
}

template<class T>
size_t Vector<T>::getSize() const {
	return size;
}

template<class T>
size_t Vector<T>::getCapacity() const {
	return capacity;
}

template<class T>
void Vector<T>::pushBack(const T& element) {
	upsizeIfNeeded();
	data[size++] = element;
}

template<class T>
void Vector<T>::pushBack(T&& element) {
	upsizeIfNeeded();
	data[size++] = std::move(element);
}

template<class T>
void Vector<T>::pushAt(const T& element, size_t index) {
	assertIndex(index);
	upsizeIfNeeded();

	for (size_t i = size; i > index; i--) {
		data[i] = data[i - 1];
	}

	data[index] = element;
	size++;
}

template<class T>
void Vector<T>::pushAt(T&& element, size_t index) {
	assertIndex(index);
	upsizeIfNeeded();

	for (size_t i = size; i > index; i--) {
		data[i] = data[i - 1];
	}

	data[index] = std::move(element);
	size++;
}

template<class T>
T Vector<T>::popBack() {
	if (empty()) {
		throw std::exception("Vector is empty");
	}
	return data[size--];
}

template<class T>
T Vector<T>::popAt(size_t index) {
	assertIndex(index);
	downsizeIfNeeded();

	T temp = data[index];
	size--;
	for (size_t i = index; i < size; i++) {
		data[i] = data[i + 1];
	}

	return data[index];
}

template<class T>
bool Vector<T>::empty() const {
	return size == 0;
}

template<class T>
void Vector<T>::clear() {
	size = 0;
}

template<class T>
void Vector<T>::shrinkToFit() {
	resize(size);
}

template<class T>
T& Vector<T>::operator[](size_t index) {
	assertIndex(index);

	return data[index];
}

template<class T>
const T& Vector<T>::operator[](size_t index) const {
	assertIndex(index);

	return data[index];
}

template<class T>
void Vector<T>::move(Vector&& other) {
	size = other.size;
	capacity = other.capacity;
	data = other.data;
	other.data = nullptr;
}

template<class T>
void Vector<T>::copyFrom(const Vector& other) {
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];

	for (size_t i = 0; i < other.size; i++) {
		data[i] = other.data[i];
	}
}

template<class T>
void Vector<T>::free() {
	delete[] data;
	data = nullptr;
	size = capacity = 0;
}

