#pragma once
#include "MyString.h"
class Student
{
private:
	MyString name;
	size_t FN;
	size_t* grades;
	size_t capacity;

	void resize(size_t newCap);
	void free();
	void copyFrom();
public:
	Student();
	Student(const char* name, size_t FN);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	MyString& getName()const;
	size_t getFN()const;
	size_t getGradeByIndex(size_t index)const;
	void setName(const char* name);
	void setFN(size_t FN);
	void addGrade(size_t grade);

};

