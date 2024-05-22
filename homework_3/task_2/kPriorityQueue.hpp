#pragma once
#include"Vector.hpp"
#include "Queue.hpp"

template<typename T>
class kPriorityQueue
{
private:
	Vector < MyQueue<T>> priorityQueue;
	size_t k;

public:
	kPriorityQueue(size_t k);

	void push(const T& obj, size_t priority);
	void push(T&& obj, size_t priority);
	
	void pop();
	const T& peek()const;

	bool isEmpty()const;
};

template<typename T>
kPriorityQueue<T>::kPriorityQueue(size_t k):k(k), priorityQueue(k){
}

template<typename T>
void kPriorityQueue<T>::push(T&& obj,size_t priority) {
	if (priority >= k) {
		throw std::exception("Out of range");
	}
	priorityQueue[priority].push(std::move(obj));
}

template<typename T>
void kPriorityQueue<T>::push(const T& obj, size_t priority) {
	if (priority >= k) {
		throw std::exception("Out of range");
	}
	priorityQueue[priority].push(obj);
}

template<typename T>
void kPriorityQueue<T>::pop() {
	for (int i = k-1; i>=0; i--) {
		if (!priorityQueue[i].isEmpty()) {
			priorityQueue[i].pop();
			return;
		}
	}
	throw std::runtime_error("The queue is empty");
}

template<typename T>
const T& kPriorityQueue<T>::peek()const {
	for (int i = k-1; i>=0; i--) {
		if (!priorityQueue[i].isEmpty()) {
			return priorityQueue[i].peek();
		}
	}
	throw std::runtime_error("The queue is empty");
}

template<typename T>
bool kPriorityQueue<T>::isEmpty()const {
	bool flag = true;
	for (size_t i = 0; i < k; i++) {
		if (!priorityQueue[i].isEmpty())
			flag = false;
	}
	return flag;
}