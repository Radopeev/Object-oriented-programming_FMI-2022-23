#include "Table.h"
#include "Functions.h"
#pragma warning(disable:4996)

using namespace Functions;

void Table::numOfColumnValidator(size_t columns)const {
	assert(columns < MAX_COLUMNS );
}

void Table::numOfColumnUpdate(size_t i) {
	if (i > numOfColumns) {
		numOfColumns = i;
	}
}

void Table::paddingAssignment() {
	for (size_t i = 0; i < numOfColumns; i++) {
		for (size_t j = 0; j < column[i].getNumOfRow(); j++) {
			size_t columnLength = strlen(column[i].getRowValue(j));
			if (columnLength > padding) {
				padding = columnLength;
			}
		}
	}
}

void Table::alignemntOfColumn() {
	for (size_t i = 0; i < numOfColumns; i++) {
		column[i].setAlignement(alignmentChecker(column[i].getRowValue(SECOND_ROW_CONST)));
	}
}

void Table::printOrWriteRow(size_t rowNum, std::ostream& output) const {
	output << PIPE;
	for (size_t i = 0; i < numOfColumns; i++) {
		switch (column[i].getAlignement())
		{
		case Alignments::left: left(column[i].getRowValue(rowNum), padding, output); break;
		case Alignments::center: center(column[i].getRowValue(rowNum), padding, output); break;
		case Alignments::right: right(column[i].getRowValue(rowNum), padding, output); break;
		default:
			break;
		}
		output << PIPE;
	}
	output << std::endl;
}

void Table::readRowFromFile(const char* buffer) {
	size_t index = 0;
	std::stringstream ss(buffer);
	ss.seekg(1, std::ios::beg);
	while (true) {
		ss.get();
		char value[MAX_CELL_SYMBOLS];
		ss.getline(value, MAX_CELL_SYMBOLS, PIPE);
		column[index].setRowValue(value, column[index].getNumOfRow());
		column[index].numOfRowIterator();
		if (ss.eof()) {
			break;
		}
		numOfColumnValidator(++index);
	}
	numOfColumnUpdate(index);
}

void Table::gettingMaxRows() {
	for (size_t i = 0; i < numOfColumns; i++) {
		if (column[i].getNumOfRow() > maxRows) {
			maxRows = column[i].getNumOfRow();
		}
	}
}
void Table::removingSpacesFromTable() {
	for (size_t i = 0; i < numOfColumns; i++) {
		for (size_t j = 0; j < column[i].getNumOfRow(); j++) {
			if (areThereCharactersLeft(column[i].getRowValue(j), 0)) {
				char* modifiedValue = removeSpaces(column[i].getRowValue(j));
				column[i].setRowValue(modifiedValue, j);
				delete[] modifiedValue;
			}
		}
	}
}

void Table::readTableFromFile(std::ifstream& myFile) {
	while (true) {
		if (myFile.eof()) {
			break;
		}
		char buffer[MAX_BUFFER_SIZE];
		myFile.getline(buffer, MAX_BUFFER_SIZE);
		readRowFromFile(buffer);
		myFile.get();
	}
	formattingTable();
}

void Table::printOrWriteTable(std::ostream& output) const {
	for (size_t i = 0; i < maxRows; i++) {
		printOrWriteRow(i, output);
	}
}

int Table::findColumnValue(const char* name)const {
	for (size_t i = 0; i < numOfColumns; i++) {
		if (strcmp(column[i].getRowValue(MAIN_ROW_CONST),name) == 0) {
			return i;
		}
	}
	return -1;
}

int Table :: findRowValue(const char* name, size_t index,const char* newName) {
	for (size_t i = 1; i < column[index].getNumOfRow(); i++) {
			if (strcmp(column[index].getRowValue(i), name) == 0) {
				column[index].setRowValue(newName, i);
				return i;
			}
	}
	return -1;
}

bool Table::changeColumnName(const char* forChange, const char* newName) {
	int index = findColumnValue(forChange);
	if (index != -1) {
		column[index].setRowValue(newName, MAIN_ROW_CONST);
		return true;
	}
	return false;
}

void Table::addRow(std::stringstream& line) {
	for (size_t i = 0; i < numOfColumns; i++) {
		char buff[MAX_CELL_SYMBOLS];
		line >> buff;
		column[i].setRowValue(buff, column[i].getNumOfRow());
		column[i].numOfRowIterator();
	}
	maxRows++;
}

bool Table::changeRowByNum(size_t changingNum, const char* columnName, const char* newName) {
	int index = findColumnValue(columnName);
	if (index != -1) {
		column[index].setRowValue(newName, changingNum + 1);
		return true;
	}
	return false;
}

bool Table::changeRowByColumnName(const char* columnName, const char* forChange, const char* newName) {
	int columnIndex = findColumnValue(columnName);
	if(columnIndex!=-1){
		int valueForChangeIndex = findRowValue(forChange, columnIndex, newName);
		if (valueForChangeIndex != -1) {
			column[columnIndex].setRowValue(newName, valueForChangeIndex);
			return true;
		}
	}
	return false;
}

bool Table::printSelected(const char* columnName, const char* keyName) {
	bool isThereAtLeastOne = false;
	int columnIndex = findColumnValue(columnName);
	if (columnIndex != -1) {
		printOrWriteRow(MAIN_ROW_CONST, std::cout);
		printOrWriteRow(SECOND_ROW_CONST, std::cout);
		for (size_t i = 1; i < column[columnIndex].getNumOfRow(); i++) {
			if (strcmp(column[columnIndex].getRowValue(i), keyName) == 0) {
				printOrWriteRow(i, std::cout);
				isThereAtLeastOne = true;
			}
		}
	}
	return isThereAtLeastOne;
}

void Table::formattingTable() {
	removingSpacesFromTable();
	alignemntOfColumn();
	paddingAssignment();
	gettingMaxRows();
}