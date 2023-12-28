#include <iostream>
using namespace std;
const int MAX_NAME_LENGTH = 30;
struct Students {
	char name[MAX_NAME_LENGTH + 1];
	unsigned int facNum;
};

void readStudent(Students& student, char(&name)[30], int& facNum, int& index) {
	index = 0;
	cout << "Enter student name:" << endl;
	cin.getline(name, MAX_NAME_LENGTH);
	cout << "Enter faculty numbeer:" << endl;
	cin >> facNum;
	while (name[index] != '\0') {
		student.name[index] = name[index];
		index++;
	}
	student.facNum = facNum;
}

void printStudent(const Students student, int& index) {
	cout << "Name:";
	for (int j = 0; j < index; j++) {
		cout << student.name[j];
	}
	cout << endl;
	cout << "Faculty number:" << student.facNum;
}

int main()
{
	char name[30];
	int facNum, index=0;
	Students student;
	readStudent(student, name, facNum, index);
	printStudent(student, index);
	Students st = { "Kolio", 10 };
	//Students pSt = &st;
	//const Students pCSt = &st;
	Students* const cPSt = &st;
	const Students* const cpCSt = &st;
	Students& refSt = st;
	const Students& refCSt = st;
}