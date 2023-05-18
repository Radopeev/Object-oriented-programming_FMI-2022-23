//This includes class MyString from https://github.com/Angeld55/Object-oriented_programming_FMI
#include <iostream>
#include"StringCreaterPieceByPiece.h"
int main()
{
	//Example
	StringCreaterPieceByPiece sc(2);

	sc.addPiece("test");
	sc.addPiece();
	sc.addPiece("football");

	sc[1] << " friends ";
	" Hello " >> sc[1];
	101111111 >> sc[2];

	MyString result1 = sc.getString(); 
	std::cout << result1<<std::endl;
	sc.swapPieces(1, 2);
	MyString result2 = sc.getString(); 
	std::cout << result2 << std::endl;
	sc.removePiece(1);
	MyString result3 = sc.getString();
	std::cout << result3 << std::endl;
}