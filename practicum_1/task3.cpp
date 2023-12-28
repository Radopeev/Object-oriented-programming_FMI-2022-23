#include <iostream>
using namespace std;
void read(int& n, int& m) {
    std::cout << "N:";
    std::cin >> n;
    std::cout << "M:";
    std::cin >> m;
}
int main()
{
    int n, m;
    read(n, m);
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int** transpose = new int*[m];
    for (int i = 0; i < m; i++) {
        transpose[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transpose[i][j] = arr[j][i];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        delete transpose[i];
    }
    delete[] transpose;
    for (int i = 0; i < n; i++) {
        delete arr[i];
    }
    delete[] arr;
}