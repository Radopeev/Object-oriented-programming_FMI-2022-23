#include<iostream>
using namespace std;
int count(int* arr, char symbol, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > (int)symbol) {
			count++;
		}
	}
	return count;
}
int main() {
	int n;
	cout << "N:" << endl;
	cin >> n;
	int* arr = new int[n];
	char symbol;
	cout << "Symbol:" << endl;
	cin >> symbol;
	cout << count(arr, symbol, n);
	return 0;
}