//This solution includes Class Time and Class Date taken from https://github.com/Angeld55/Object-oriented_programming_FMI
#include <iostream>
#include "TextFileManager.h"
#pragma warning(disable:4996)
int main()
{
	//Example
	TextFileManager fs(5);
	fs.addFile("test.txt", 14, 0, 0, 20, 3, 2023, "rwxr--r--");
	fs.editFile("test.txt", "Hello, world!", 14, 10, 0, 20, 3, 2023, 'u');
	fs.editFile("test.txt", "Hello, world!", 14, 11, 0, 20, 3, 2023, 'o');
	fs.addInFile("test.txt", "Hello, my friend!", 14, 13, 0, 20, 3, 2023,'u');
	fs.editFile("test.txt", "Hello", 14, 15, 0, 20, 3, 2023, 'u');
	fs.addFile("attest.txt", 14, 30, 0, 20, 3, 2023, "rwxr--r--");
	fs.removeFile("attest.txt");
	fs.addFile("attest.txt", 14, 35, 0, 20, 3, 2023, "rwxr--r--");
	fs.changeRights("attest.txt", 'u', 'w');
	fs.changeRights("attest.txt", 'u', 'w');
	fs.changeRights("attest.txt", 'u', 'r');
	fs.printFile("attest.txt", 'u');
	fs.printFile("test.txt", 'o');
	fs.printFile("attest.txt", 'o');
	fs.printFileInfo("test.txt");
	fs.sort(SortOptions::name);
	fs.print();
	fs.sort(SortOptions::modificationTime);
	fs.print();

}
