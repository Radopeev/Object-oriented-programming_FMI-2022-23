#include "Student.h"

void Student::resize(size_t newCap) {

}
void Student::free();
void Student::copyFrom();

Student::Student();
Student::Student(const char* name, size_t FN);
Student::Student(const Student& other);
Student& Student::operator=(const Student& other);
Student::~Student();

MyString& Student::getName()const;
size_t Student::getFN()const;
size_t Student::getGradeByIndex(size_t index)const;
void Student::setName(const char* name);
void Student::setFN(size_t FN);
void Student::addGrade(size_t grade);