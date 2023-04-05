#include <iostream>
#include<fstream>
using namespace std;
const int BUFFER_SIZE = 1024;
int print(ifstream& in) {
    int sum, multiplication;
    if (!in.is_open()) {
        return -1;
    }
    in >> sum >> multiplication;
    cout << sum - multiplication;
}
int main()
{
    int a, b, c;
    cout << "Three numbers:";
    cin >> a >> b >> c;
    int sum = a + b + c;
    int multiplication = a * b * c;
    ofstream out("result.txt");
    out << sum << " " << multiplication;
    out.close();
    ifstream in("result.txt");
    print(in);
    out.close();
    in.close();
}