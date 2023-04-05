#include <iostream>
#include <fstream>
using namespace std;
const int MAX_SIZE = 128;
enum class Category {
	OKN,
	M,
	OPM,
	PR
};
enum class Type {
	Exam,
	Project,
	Test
};
struct Discipline {
	char ID[MAX_SIZE];
	char name[MAX_SIZE];
	Category category;
	int credits;
	Type type;
};
void adddingDiscipline(ofstream& out, Discipline* discipline) {
	out << discipline->ID << ", " << discipline->name << ", ";
	switch (discipline->category) {
		case Category::OKN:out << "OKN, "; break;
		case Category::M:out << "M, "; break;
		case Category::OPM:out << "OPM, "; break;
		case Category::PR:out << "PR, "; break;
	}
	out << discipline->credits << ", ";
	switch (discipline->type) {
		case Type::Exam:out << "Exam, "; break;
		case Type::Project:out << "Project, "; break;
		case Type::Test:out << "Test, "; break;
	}
}
void printingDiscipline(instream& in) {

}
int main() {
	ofstream out;
	out.open("discipline.csv");
}