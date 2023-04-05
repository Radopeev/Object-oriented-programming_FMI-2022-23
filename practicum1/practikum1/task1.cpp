int func1(int a, int b) {
	if (a < b) {
		return a;
	}
	else return b;
}
int func2(int* a, int* b) {
	if (*a < *b) {
		return *a;
	}
	else return *b;
}
int func3(const int& a, const int& b) {
	if (a < b) {
		return a;
	}
	else return b;
}

