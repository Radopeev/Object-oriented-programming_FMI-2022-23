#pragma once

template<typename T,typename Q>
class PairOfOptionals {
	T* dataOne;
	Q* dataTwo;

	void free();
	void copyFrom(const PairOfOptionals& other);
	void move(PairOfOptionals&& other);
public:
	PairOfOptionals(T* dataOne, Q* dataTwo);
	PairOfOptionals(const PairOfOptionals& other);
	PairOfOptionals(PairOfOptionals&& other);
	PairOfOptionals& operator=(const PairOfOptionals& other);
	PairOfOptionals& operator=(PairOfOptionals&& other);
	~PairOfOptionals();

	void setDataOne(const T& newData);
	void setDataTwo(const Q& newData);
	
	const T& getDataOne()const;
	const Q& getDataTwo()const;
	
	void deleteDataOne();
	void  deleteDataTwo();

	bool isEmptyDataOne()const;
	bool  isEmptyDataTwo()const;

	bool operator==(const PairOfOptionals& other)const;
	bool operator!=(const PairOfOptionals& other)const;
};

template<typename T, typename Q>
void PairOfOptionals<T, Q>::free() {
	delete dataOne;
	delete dataTwo;
}
template<typename T, typename Q>
void PairOfOptionals<T, Q>::copyFrom(const PairOfOptionals& other) {
	dataOne = new T(other.dataOne);
	dataTwo = new Q(other.dataTwo);
}
template<typename T, typename Q>
void PairOfOptionals<T, Q>::move(PairOfOptionals&& other) {

}

template<typename T,typename Q>
PairOfOptionals<T,Q>::PairOfOptionals(T* dataOne, Q* dataTwo) {
	setDataOne(dataOne);
	setDataTwo(dataTwo);
}

template<typename T,typename Q>
PairOfOptionals<T, Q>::PairOfOptionals(const PairOfOptionals& other) {
	copyFrom(other);
}

template<typename T, typename Q>
PairOfOptionals<T, Q>::PairOfOptionals(PairOfOptionals&& other) {
	move(std::move(other));
}
template<typename T, typename Q>
PairOfOptionals<T,Q>& PairOfOptionals<T, Q>::operator=(const PairOfOptionals& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
template<typename T, typename Q>
PairOfOptionals<T,Q>& PairOfOptionals<T, Q>::operator=(PairOfOptionals&& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
template<typename T, typename Q>
PairOfOptionals<T, Q>::~PairOfOptionals() {
	free();
}

template<typename T, typename Q>
void PairOfOptionals<T, Q>::setDataOne(const T& newData) {
	this->dataOne = newData;
}
template<typename T, typename Q>
void PairOfOptionals<T, Q>::setDataTwo(const Q& newData) {
	this->dataTwo = newData;
}
template<typename T, typename Q>
const T& PairOfOptionals<T, Q>::getDataOne()const {
	return dataOne;
}
template<typename T, typename Q>
const Q& PairOfOptionals<T, Q>::getDataTwo()const {
	return dataTwo;
}
template<typename T, typename Q>
void PairOfOptionals<T, Q>::deleteDataOne() {
	delete dataOne;
}
template<typename T, typename Q>
void  PairOfOptionals<T, Q>::deleteDataTwo() {
	delete dataTwo;
}
template<typename T, typename Q>
bool PairOfOptionals<T, Q>::isEmptyDataOne()const {
	return dataOne;
}
template<typename T, typename Q>
bool  PairOfOptionals<T, Q>::isEmptyDataTwo()const {
	return dataTwo;
}


