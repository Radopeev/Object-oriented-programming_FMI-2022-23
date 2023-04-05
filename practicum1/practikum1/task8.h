#include <iostream>
using namespace std;
struct Students {
	char name[30];
	int grades[30];
	int average;
};
void swap(Students& a, Students& b) {
	Students temp = a;
	a = b;
	b = temp;
}
void selectionSort(Students* group, size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < length; j++) {
			if (group[minIndex].average > group[j].average) {
				minIndex = j;
			}
		}
		if (minIndex != i)
			swap(group[i], group[minIndex]);
	}
}
int numOfStudents() {
	int n;
	cout << "Enter number of students int group";
	cin >> n;
	return n;
}
void createStudent(Students& student, const char(&name)[30], const int& gradesNum) {
	int sum = 0;
	int len1 = sizeof(name) / sizeof(char);
	for (int i = 0; i < len1; i++) {
		student.name[i] = name[i];
	}
	int* grades = new int[gradesNum];
	for (int i = 0; i < gradesNum; i++) {
		cout << "Grade:";
		cin >> student.grades[i];
		sum += student.grades[i];
	}
	student.average = sum / gradesNum;
}
void createGroup(Students* group, int& n) {
	char name[30];
	int gradesNum, n = numOfStudents(), average = 0;
	Students* groupOfStudents = new Students[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter name of the student:" << endl;
		cin.getline(name, 30);
		cout << "Enter number of grades this student has: " << endl;
		cin >> gradesNum;
		createStudent(groupOfStudents[i], name, gradesNum);
		cin.ignore();
	}
	group = groupOfStudents;
}
int scholarship(Students* group, int& min) {
	int n;
	createGroup(group, n);
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (group[i].average > min) {
			count++;
		}
	}
	return count;
}
int sortScholarships(Students* group, int& count, int& min) {
	int n;
	createGroup(group, n);
	int count = scholarship(group, min);
	Students* scholars = new Students[count];
	for (int i = 0; i < n; i++) {
		if (group[i].average > min) {
			scholars[i] = group[i];
		}
	}
	selectionSort(scholars, count);
}

