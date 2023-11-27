#pragma once
#include "constants.h"
#include "Alignments.h"

using namespace GlobalConstants;
using namespace Messages;

class Column {
private:
	struct Row {
		char value[MAX_CELL_SYMBOLS];
	};
	bool isValidColumn = true;
	size_t numOfRow = 0;
	Alignments alignmentFlag;
	Row rows[MAX_ROWS];
public:
	void numOfRowIterator();
	void setNumOfRow(size_t numOfRow);
	void setAlignement(const Alignments& alignmentFlag);
	void setRowValue(const char* rowValue, size_t index);
	size_t getNumOfRow() const;
	bool getIsValid() const;
	const Alignments& getAlignement() const;
	const char* getRowValue(size_t index) const;
};
