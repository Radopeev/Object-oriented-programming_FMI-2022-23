#pragma once

namespace GlobalConstants {
	const size_t MAX_BUFFER_SIZE = 200;
	const size_t MAX_CELL_SYMBOLS = 20;
	const size_t MAIN_ROW_CONST = 0;
	const size_t SECOND_ROW_CONST = 1;
	const size_t MAX_COLUMNS = 10;
	const size_t MAX_ROWS = 50;
	const char GREATER_THAN = '>';
	const char PIPE = '|';

}

namespace Commands {
	const char PRINT[] = "print";
	const char ADD_ROW[] = "addRow";
	const char CHANGE[] = "change";
	const char CHANGE_ROW[]="changeRow";
	const char SELECT_WHERE[] = "selectWhere";
	const char SAVE[] = "save";
}

namespace Messages {
	const char TABLE_LOADED[] = "Table loaded successfully.";
	const char OPERATION_EXECUTED[] = "Operation successfully executed!";
	const char TABLE_SAVED[] = "File successfully saved!";
	const char NOT_FOUND[] = "Name not found";
}