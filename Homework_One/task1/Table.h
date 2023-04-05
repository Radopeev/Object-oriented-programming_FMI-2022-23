#pragma once
#include<iostream>
#include<sstream>
#include<cassert>
#include<fstream>
#include "Alignments.h"
#include "Column.h"
#include "Functions.h"
#include "constants.h"
#pragma warning(disable:4996)

using namespace Messages;

class Table {
private:
	size_t maxRows = 0;
	size_t numOfColumns = 0;
	size_t padding = 0;
	Column column[MAX_COLUMNS];

	int findColumnValue(const char* name)const;
	int findRowValue(const char* name, size_t index,const char* newName);
	void formattingTable();
	void gettingMaxRows();
	void numOfColumnValidator(size_t i)const;
	void numOfColumnUpdate(size_t i);
	void paddingAssignment();
	void alignemntOfColumn();
	void printOrWriteRow(size_t rowNum, std::ostream& output)const;
	void readRowFromFile(const char* buffer);
	void removingSpacesFromTable();
public:
	void readTableFromFile(std::ifstream& myFile);
	void printOrWriteTable(std::ostream& output) const;
	bool changeColumnName(const char* forChange, const char* newName);
	void addRow(std::stringstream& line);
	bool changeRowByNum(size_t changingNum, const char* columnName, const char* newName);
	bool changeRowByColumnName(const char* columnName, const char* forChange, const char* newName);
	bool printSelected(const char* columnName, const char* keyName);
};
