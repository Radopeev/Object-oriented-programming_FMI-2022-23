#pragma once 
#include<iostream>

template<typename T>
void sort(T* arr, size_t size) {
	for (size_t i = 1; i < size; i++) {
		T currentObj = arr[i];

		size_t j = i - 1;
		while (j >= 0 && arr[j] > currentObj) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = currentObj;
	}
}

template<>
void sort(char* arr, size_t size){
	size_t arrLength = strlen(arr);
	char* copy = new char[arrLength];
	for (size_t i = 0; i < arrLength; i++) {
		copy[i] = arr[i];
	}

	int counter[256] = { 0 };
	for (size_t i = 0; i < size; i++) {
		counter[arr[i]]++;
	}
	for (size_t i = 1; i < 256; i++) {
		counter[i] += counter[i - 1];
	}
	for (int i = arrLength - 1; i >= 0; i--) {
		arr[counter[copy[i]] - 1] = copy[i];
		--counter[copy[i]];
	}

	delete[] copy;
}