#include "MyString.h"

const size_t MyString::SMALL_STRING_CAPACITY = sizeof(myUnion);

MyString::MyString(size_t capacity)
{
	size = capacity - 1;
	if (!isSSO()) {
		myUnion.heap.capacity = capacity;
		myUnion.heap.dynamicData = new char[capacity]();
	}
}
void MyString::memoryAllocation(size_t newCapacity) {
	char bufferForStaticData[SMALL_STRING_CAPACITY];
	strcpy(bufferForStaticData, myUnion.staticData);
	myUnion.heap.capacity = newCapacity ;
	myUnion.heap.dynamicData = new char[myUnion.heap.capacity]();
	strcpy(myUnion.heap.dynamicData, bufferForStaticData);
}

void MyString::resizeForConcatenations() {
	char* result = new char[myUnion.heap.capacity];
	result[0] = '\0'; 
	strcat(result, myUnion.heap.dynamicData);
	delete[] myUnion.heap.dynamicData;
	myUnion.heap.dynamicData = result;
}
MyString& MyString::operator+=(const MyString& other)
{
	bool isThisStringSS0 = isSSO(), isOtherStringSSO = other.isSSO();
	if (isThisStringSS0 && isOtherStringSSO && (size + other.size)<=SMALL_STRING_CAPACITY) {
		size += other.size;
		strcat(myUnion.staticData,other.myUnion.staticData);
		return *this;
	}
	else if (isThisStringSS0 && isOtherStringSSO && (size + other.size) > SMALL_STRING_CAPACITY) {
		size += other.size;
		memoryAllocation(size+1);
		strcat(myUnion.heap.dynamicData, other.myUnion.staticData);
		return *this;
	}
	else if (!isThisStringSS0 && isOtherStringSSO) {
		size += other.size;
		myUnion.heap.capacity = size +2;
		resizeForConcatenations();
		strcat(myUnion.heap.dynamicData, other.myUnion.staticData);
		return *this;
	}
	else if (isThisStringSS0 && !isOtherStringSSO) {
		size += other.size;
		memoryAllocation(size+1);
		strcat(myUnion.heap.dynamicData, other.myUnion.heap.dynamicData);
		return *this;
	}
	else {
		size += other.size;
		myUnion.heap.capacity =size+2;
		resizeForConcatenations();
		strcat(myUnion.heap.dynamicData, other.myUnion.heap.dynamicData);
		return *this;
	}
}

MyString::MyString() : MyString(1)
{
	myUnion.staticData[0]= '\0';
}

MyString::MyString(const char* data) : MyString(strlen(data) + 1)
{
	if (!isSSO()) {
		strcpy(myUnion.heap.dynamicData, data);
	}
	else {
		strcpy(myUnion.staticData, data);
		size = strlen(data);
	}
}
MyString::MyString(const MyString& other){
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void MyString::free()
{
	if (!isSSO()) {
		delete[] myUnion.heap.dynamicData;
		myUnion.heap.capacity = 0;
	}
	else {
		myUnion.staticData[0] = '\0';
	}
	size = 0;
}
bool MyString::isSSO() const
  {
	if (size >= SMALL_STRING_CAPACITY) {
		return false;
	}
	return true;
}
MyString::~MyString()
{
	free();
}
size_t MyString::length() const
{
	return size;
}
void MyString::copyFrom(const MyString& other)
{
	if (!other.isSSO()) {
		size = other.size;
		myUnion.heap.capacity = other.myUnion.heap.capacity;
		myUnion.heap.dynamicData = new char[other.myUnion.heap.capacity]();
		strcpy(myUnion.heap.dynamicData, other.myUnion.heap.dynamicData);
	}
	else {
		strcpy(myUnion.staticData, other.myUnion.staticData);
	}
	size = other.size;
}

char& MyString::operator[](size_t index)
{
	if (!isSSO()){
		return myUnion.heap.dynamicData[index];
	}
	return myUnion.staticData[index];
}

char MyString::operator[](size_t index) const 
{
	if (!isSSO()) {
		return myUnion.heap.dynamicData[index];
	}
	return myUnion.staticData[index];
}

MyString MyString::substr(size_t begin, size_t howMany) const
{

	MyString res(howMany + 1);
	if (!isSSO()) {
		if (begin + howMany >size)
			throw std::length_error("Error, Substr out of range");
		for (size_t i = 0; i < howMany; i++)
			res.myUnion.heap.dynamicData[i] = myUnion.heap.dynamicData[begin + i];
	}
	else {
		if (begin + howMany > size)
			throw std::length_error("Error, Substr out of range");
		for (size_t i = 0; i < howMany; i++)
			res.myUnion.staticData[i] = myUnion.staticData[begin +i];
	}
	res[howMany] = '\0';
	return res;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
	MyString result(lhs.size + rhs.size +1);
	bool isLhsSSO = lhs.isSSO(), isRhsSSO = rhs.isSSO();
	if (isLhsSSO && isRhsSSO) {
		strcpy(result.myUnion.staticData,lhs.myUnion.staticData);
		strcat(result.myUnion.staticData, lhs.myUnion.staticData);
	}
	else if (!isLhsSSO && isRhsSSO) {
		strcpy(result.myUnion.heap.dynamicData, lhs.myUnion.heap.dynamicData);
		strcat(result.myUnion.heap.dynamicData, rhs.myUnion.staticData);
	}
	else if (isLhsSSO && !isRhsSSO) {
		strcpy(result.myUnion.heap.dynamicData, lhs.myUnion.staticData);
		strcat(result.myUnion.heap.dynamicData, rhs.myUnion.heap.dynamicData);
	}
	else {
		strcpy(result.myUnion.heap.dynamicData, lhs.myUnion.heap.dynamicData);
		strcat(result.myUnion.heap.dynamicData, rhs.myUnion.heap.dynamicData);
	}
	return result;
}
const char* MyString::c_str() const
{
	if (!isSSO()) {
		return myUnion.heap.dynamicData;
	}
	return myUnion.staticData;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is >> buff; 
	if (!str.isSSO()) {
		str.free();
	}
	str = MyString(buff);
	return is;
}
bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}