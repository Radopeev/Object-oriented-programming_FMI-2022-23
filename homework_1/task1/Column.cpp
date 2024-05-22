#include "Column.h"
#include<cstring>
#include <iostream>
#include<cassert>
#pragma warning (disable:4996)

void Column::numOfRowIterator() {
	numOfRow++;
	assert(numOfRow < MAX_ROWS);
}

bool Column::getIsValid()const {
	return isValidColumn;
}

void Column::setNumOfRow(size_t numOfRow) {
	this->numOfRow = numOfRow;
}

void Column::setAlignement(const Alignments& alignmentFlag) {
	this->alignmentFlag = alignmentFlag;
}

void Column::setRowValue(const char* rowValue, size_t index) {
	strcpy(this->rows[index].value, rowValue);
}

size_t Column::getNumOfRow() const {
	return numOfRow;
}

const Alignments& Column::getAlignement() const {
	return alignmentFlag;
}

const char* Column::getRowValue(size_t index) const {
	return rows[index].value;
}