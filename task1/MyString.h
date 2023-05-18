#pragma once
#include <iostream>
#pragma warning(disable:4996)
class MyString
{
private:
	union {
		struct
		{
			char* dynamicData;
			size_t capacity;
		}heap;
		char staticData[sizeof(heap)];
	}myUnion;

	static const size_t SMALL_STRING_CAPACITY;
	size_t size;
	
	void memoryAllocation(size_t newCapacity);
	void resizeForConcatenations();
	
	void copyFrom(const MyString& data);
	void free();
	explicit MyString(size_t capacity); 
public:
	bool isSSO()const;
	MyString();
	MyString(const char* data);

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
 	
	size_t length() const;
	MyString& operator+=(const MyString& other);

	MyString substr(size_t begin, size_t howMany) const;

	char& operator[](size_t index);
	char operator[](size_t index) const;
	~MyString();

	const char* c_str() const;

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream&, MyString& str);
};
MyString operator+(const MyString& lhs, const MyString& rhs);

std::ostream& operator<<(std::ostream& os, const MyString& str);

std::istream& operator>>(std::istream& os, const MyString& str);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);