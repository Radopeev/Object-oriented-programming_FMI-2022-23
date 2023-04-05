#include "Menu.h"

void fileNameInput(Table& table) {
	char fileName[MAX_BUFFER_SIZE];
	while (true) {
		std::cout << GREATER_THAN;
		std::cin >> fileName;
		std::cin.ignore();
		std::ifstream myFile(fileName);
		if (myFile.is_open()) {
			table.readTableFromFile(myFile);
			std::cout << TABLE_LOADED << std::endl;
			myFile.close();
			break;
		}
	}
}
void menu(Table& table) {
	fileNameInput(table);
	while (true) {
		char userInput[MAX_BUFFER_SIZE];
		char command[MAX_BUFFER_SIZE];
		std::cout << GREATER_THAN;
		std::cin.getline(userInput, MAX_BUFFER_SIZE);
		std::stringstream ss(userInput);
		ss >> command;
		if (strcmp(command, PRINT) == 0) {
			table.printOrWriteTable(std::cout);
			std::cout << std::endl;
		}
		else if (strcmp(command, ADD_ROW) == 0) {
			table.addRow(ss);
			std::cout << OPERATION_EXECUTED << std::endl << std::endl;
		}
		else if (strcmp(command, CHANGE) == 0) {
			char columnName[MAX_CELL_SYMBOLS], forChange[MAX_CELL_SYMBOLS];
			ss >> columnName >> forChange;
			if (!ss.eof()) {
				char newName[MAX_CELL_SYMBOLS];
				ss >> newName;
				if (table.changeRowByColumnName(columnName, forChange, newName))
				{
					std::cout << OPERATION_EXECUTED << std::endl << std::endl;
				}
				else std::cout << NOT_FOUND << std::endl;
			}
			else {
				if (table.changeColumnName(columnName, forChange))
				{
					std::cout << OPERATION_EXECUTED << std::endl << std::endl;
				}
				else std::cout << NOT_FOUND << std::endl;
			}
		}
 		else if (strcmp(command, CHANGE_ROW) == 0) {
			size_t changeNum;
			char columnName[MAX_CELL_SYMBOLS], newName[MAX_CELL_SYMBOLS];
			ss >> changeNum >> columnName >> newName;
			if (table.changeRowByNum(changeNum, columnName, newName))
			{
				std::cout << OPERATION_EXECUTED << std::endl << std::endl;
			}
			else std::cout << NOT_FOUND << std::endl;
		}
		else if (strcmp(command, SELECT_WHERE) == 0) {
			char columnName[MAX_CELL_SYMBOLS], valueForPrint[MAX_CELL_SYMBOLS];
			ss >> columnName >> valueForPrint;
			if (!table.printSelected(columnName, valueForPrint))
			{
				std::cout << NOT_FOUND << std::endl; 
			}
			std::cout << std::endl;
		}
		else if (strcmp(command, SAVE) == 0) {
			char newFileName[MAX_CELL_SYMBOLS];
			ss >> newFileName;
			std::ofstream newFile(newFileName);
			table.printOrWriteTable(newFile);
			std::cout << TABLE_SAVED;
			newFile.close();
			break;
		}
	}
}