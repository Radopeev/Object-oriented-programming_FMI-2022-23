#include <iostream>
#include <fstream>
using namespace std;
int getFileSize(std::ifstream& in) {
	if (!in.is_open()) {
		return -1;
	}
	int currentPos = in.tellg();
	in.seekg(0, ios::end);
	int size = in.tellg();
	in.seekg(currentPos, ios::beg);
	return size;
}
int main()
{
    ifstream in("text.txt");
    int count = getFileSize(in);
    cout << count;
	in.close();
    return 0;
}