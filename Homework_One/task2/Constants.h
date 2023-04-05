#pragma once
namespace GlobalConstants {
    const size_t MAX_FORMAT_SYMBOLS = 4;
    const size_t MAX_NAME_SYMBOLS = 64;
    const size_t MAX_CONTENT_SYMBOLS = 512;
    const size_t MAX_ACCESS_RIGHTS_SYMBOLS = 9;
    const char USER_OWNER_CONST = 'u';
    const char GROUP_OWNER_CONST = 'g';
    const char OTHER_CONST = 'o';
    const char WRITING_CONST = 'w';
    const char READING_CONST = 'r';
    const char EXECUTION_CONST = 'e';
    const char txt_Format[] = "txt";
}

namespace Errors {
    const char TOO_MANY_FILES[] = "Error!The are too many files";
    const char NO_RIGHTS_TO_WRITE[]= "Error!You don't have rights to write.";
    const char FILE_NAME_NOT_FOUND[] = "Error! There is no file with that name.";
    const char NO_RIGHTS_TO_READ[] = "Error! You don't have rights to read.";
    const char NO_TXT_FORMAT[] = "Error! This is not a txt file.";
}
namespace PrintMessages {
    const char PRINT_NAME[] = "Name: ";
    const char SIZE[] = "Size: ";
    const char CREATION_TIME[] = "Created on: ";
    const char LAST_MODIFICATION_TIME[] = "Last modification time: ";
    const char ACCESS_RIGHTS[] = "Rights: ";
}