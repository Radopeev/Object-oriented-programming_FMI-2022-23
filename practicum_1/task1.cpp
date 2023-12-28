#include <iostream>
using namespace std;
int func1(int a, int b) {
	return (a < b) ? a : b;
}
int func2(int* a, int* b) {
	return (*a < *b) ? *a : *b;
}
int func3(const int& a, const int& b) {
	return (a < b) ? a : b;
}

int main()
{
	int* a = new int(90);
	int* b = new int(466);
	cout << func1(1, 8);
	cout << func2(a, b);
	cout << func3(447, 56);
	delete a;
	delete b;
}