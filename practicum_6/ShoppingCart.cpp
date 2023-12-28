#include "ShoppingCart.h"
#include <iostream>
#include<fstream>
#pragma warning(disable:4996)

void swap(Item& a, Item& b) {
	Item temp = a;
	a = b;
	b = temp;
}


void ShoppingCart::copyFrom(const ShoppingCart& other) {
	this->itemsCount = other.itemsCount;
	this->items = new Item[other.capacity];
	for (int i = 0; i < other.itemsCount; i++) {
		this->items[i] = other.items[i];
	}
}
void ShoppingCart::free() {
	delete[] items;
}
void ShoppingCart::resize(int newCapacity) {

	Item* newItems = new Item[newCapacity];
	for (int i = 0; i < itemsCount; i++) {
		newItems[i] = items[i];
	}
	delete[] items;
	items = newItems;
	capacity = newCapacity;
}
int ShoppingCart::find(const char* nameToFind)const {
	for (int i = 0; i < itemsCount; i++) {
		if (strcmp(items[i].getName(), nameToFind) == 0) {
			return i;
		}
	}
	return -1;
}

ShoppingCart::ShoppingCart() {
	capacity = 2;
	items = new Item[capacity];
	itemsCount = 0;
}

ShoppingCart::ShoppingCart(const ShoppingCart & other) {
	copyFrom(other);
}
ShoppingCart& ShoppingCart::operator=(const ShoppingCart & other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

void ShoppingCart::itemSwap(Item& a, Item& b) {
	Item temp = a;
	a = b;
	b = temp;
}
bool ShoppingCart::addItem(const char* name,bool isAvailable,float price) {
	int newItemIndex = find(name);
	if (newItemIndex != -1) {
		return false;
	}
	if (itemsCount == capacity)
		resize(capacity * 2);
	items[itemsCount++]=Item(name,isAvailable,price);
	return true;
}
bool ShoppingCart::removeItem(const char* name) {
	int itemForRemovalIndex = find(name);
	if (itemForRemovalIndex != -1){
		itemSwap(items[itemsCount] ,items[itemForRemovalIndex]);
		itemsCount--;
		return true;
	}
	return false;
}
int ShoppingCart::getItemsCount() const {
	return itemsCount;
}
bool ShoppingCart::isEmpty()const {
	if (itemsCount == 0) {
		return true;
	}
	return false;
}
float ShoppingCart::getPriceOf(const char* name)const {
	int index = find(name);
	if (index == -1) {
		return -1;
	}
	return items[index].getPrice();
}
float ShoppingCart::getTotalPrice()const {
	float sum = 0;
	for (int i = 0; i < itemsCount; i++) {
		sum += items[i].getPrice();
	}
	return sum;
}
void ShoppingCart::sortByName() {
	for (int i = 0; i < itemsCount - 1; i++) {
		bool hasSwaps = false;
		for (int j = 0; j < itemsCount - i - 1; j++) {
			if (strcmp(items[j].getName(),items[j+1].getName())>0) {
				swap(items[j], items[j + 1]);
				hasSwaps = true;
			}
		}

		if (!hasSwaps) {
			break;
		}
	}
}
bool ShoppingCart::saveToFile(std::ofstream& myFile)const {
	if (myFile.is_open()) {
		for (int i = 0; i < itemsCount; i++) {
			myFile << items[i].getName() << " , " << items[i].getAvailability() << " , " << items[i].getPrice() << std::endl;
		}
		return true;
	}
	return false;
}

ShoppingCart::~ShoppingCart() {
	free();
}