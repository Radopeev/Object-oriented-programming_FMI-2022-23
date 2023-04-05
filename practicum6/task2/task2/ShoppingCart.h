#pragma once
#include "Item.h"
#include<fstream>
class ShoppingCart
{
private:
	int capacity;
	int itemsCount;
	Item* items;

	void copyFrom(const ShoppingCart& other);
	void free();
	void resize(int newCapacity);
	int find(const char* nameToFind)const;
public:
	ShoppingCart();
	ShoppingCart(const ShoppingCart& other);
	ShoppingCart& operator=(const ShoppingCart& other);
	void itemSwap(Item& a, Item& b);
	bool addItem(const char* name, bool isAvailable, float price);
	bool removeItem(const char* name);
	int getItemsCount() const;
	bool isEmpty()const;
	float getPriceOf(const char* name)const;
	float getTotalPrice()const;
	void sortByName();
	bool saveToFile(std::ofstream& myFile)const;

	~ShoppingCart();
};

