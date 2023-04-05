#include <iostream>
using namespace std;
const int MAX_LENGTH = 31;
const double EPSILON = 0.00001;
struct Students {
	char name[MAX_LENGTH];
	double grades[MAX_LENGTH];
	double average;
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
		{
			swap(group[i], group[minIndex]);
		}
	}
}
void createStudent(Students& student, const char(&name)[MAX_LENGTH], const int& gradesNum) {
	double sum = 0;
	for (int i = 0; i < MAX_LENGTH; i++) {
		if (name[i] == '\0') {
			student.name[i] = name[i];
			break;
		}
		student.name[i] = name[i];
	}
	int* grades = new int[gradesNum];
	for (int i = 0; i < gradesNum; i++) {
		cout << "Grade:";
		cin >> student.grades[i];
		sum += student.grades[i];
	}
	student.average = sum / gradesNum;
	delete[] grades;
}
void createGroup(Students* group, int& n) {
	char name[MAX_LENGTH];
	int gradesNum;
	double average = 0;
	for (int i = 0; i < n; i++) {
		cout << "Enter name of the student:" << endl;
		cin.getline(name, MAX_LENGTH);
		cout << "Enter number of grades this student has: " << endl;
		cin >> gradesNum;
		createStudent(group[i], name, gradesNum);
		cin.ignore();
	}
}
int scholarship(Students* group, double& min,int& n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (group[i].average-min> EPSILON) {
			count++;
		}
	}
	return count;
}
void sortScholarships(Students* group, double& min,int& n) {
	int count = scholarship(group, min,n),j=0;
	Students* scholars = new Students[count];
	for (int i = 0; i < n; i++) {
		if (group[i].average-min> EPSILON) {
			scholars[j] = group[i];
			j++;
		}
	}
	selectionSort(scholars, count);
	for (int i = 0; i < count; i++) {
		cout << "Name: " << scholars[i].name;
		cout << endl;
		cout << "Average score: " << scholars[i].average;
		cout << endl;
	}
	delete[] scholars;
}
int main() {
	int n;
	double min;
	cout << "Enter number of students in group: ";
	cin >> n;
	cin.ignore();
	Students* group=new Students[n];
	createGroup(group, n);
	cout << "What is the minimum average score for scholarship: ";
	cin >> min;
	cout << "Number of students who get scholarships: "<< scholarship(group, min, n)<<endl;
	sortScholarships(group, min, n);
	delete[] group;
}
