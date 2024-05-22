#include <iostream>
#include "TextFileManager.h"

void TextFileManager::copyFrom(const TextFileManager& other) {
    maxFiles = other.maxFiles;
    numOfFiles = other.numOfFiles;
    files = new File[maxFiles];
    for (size_t i = 0; i < numOfFiles; i++) {
        files[i] = other.files[i];
    }
}

void TextFileManager::free() {
    delete[] files;
    numOfFiles = maxFiles = 0;
}

TextFileManager::TextFileManager(const TextFileManager& other) {
    copyFrom(other);
}

TextFileManager& TextFileManager::operator=(const TextFileManager& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

void TextFileManager::swapFiles(File& a, File& b) {
    File temp = a;
    a = b;
    b = temp;
}

TextFileManager::TextFileManager(size_t maxFiles) {
    this->maxFiles = maxFiles;
    files = new File[maxFiles];
}
void TextFileManager::addFile(const char* name,
    size_t hours, size_t min, size_t secs,
    size_t day, size_t month, size_t year, const char* accessRights)
{
    if (numOfFiles == maxFiles) {
        std::cout << TOO_MANY_FILES << std::endl;
        return;
    }
    if (textFormatValidator(name)==0) {
        files[numOfFiles].setName(name);
            files[numOfFiles].setCreationTime(hours, min, secs);
            files[numOfFiles].setCreationDate(day, month, year);
            files[numOfFiles].setAccessRights(accessRights);
            numOfFiles++;
            return;
    }  
    std::cout << NO_TXT_FORMAT << std::endl;
}

void TextFileManager::editFile(const char* name, const char* change,
    size_t hours, size_t min, size_t secs,
    size_t day, size_t month, size_t year, char group) {
    for (size_t i = 0; i < numOfFiles; i++) {
        if (strcmp(files[i].getName(), name) == 0) {
            if (files[i].checkForSomeRight(group, WRITING_CONST)) {
                files[i].fileUpdate(change, hours, min, secs, day, month, year);
                return;
            }
            else {
                std::cout << NO_RIGHTS_TO_WRITE << std::endl;
                return;
            }
        }
    }
    std::cout << FILE_NAME_NOT_FOUND << std::endl;
}
void TextFileManager::addInFile(const char* name, const char* addition,
    size_t hours, size_t min, size_t secs,
    size_t day, size_t month, size_t year, char group) {
    for (size_t i = 0; i < numOfFiles; i++) {
        if (strcmp(files[i].getName(), name) == 0) {
            if (files[i].checkForSomeRight(group, WRITING_CONST)) {
                char* currentContent = concatenate(files[i].getContent(),addition);
                files[i].fileUpdate(currentContent, hours, min, secs, day, month, year);
                delete[] currentContent;
                return;
            }
            else {
                std::cout << NO_RIGHTS_TO_WRITE << std::endl;
                return;
            }
        }
    }
    std::cout << FILE_NAME_NOT_FOUND << std::endl;
}
void TextFileManager::removeFile(const char* name) {
    for (size_t i = 0; i < numOfFiles; i++) {
        if (strcmp(files[i].getName(), name) == 0) {
            files[numOfFiles] = files[i];
            numOfFiles--;
            return;
        }
    }
    std::cout << FILE_NAME_NOT_FOUND << std::endl;
}
void TextFileManager::changeRights(const char* name, char group, char newRight) {
    for (size_t i = 0; i < numOfFiles; i++) {
        if (strcmp(files[i].getName(), name) == 0) {
            files[i].changeRightByGroup(group, newRight);
            return;
        }
    }
    std::cout<< FILE_NAME_NOT_FOUND<<std::endl;
}
void TextFileManager::printFile(const char* name, char group) const {
    for (size_t i = 0; i < numOfFiles; i++) {
        if (strcmp(files[i].getName(), name) == 0) {
            if (files[i].checkForSomeRight(group, READING_CONST)) {
                std::cout << files[i].getContent() << std::endl;
                return;
            }
            else {
                std::cout << NO_RIGHTS_TO_READ << std::endl;
                return;
            }
        }
    }
    std::cout << FILE_NAME_NOT_FOUND << std::endl;
}
void TextFileManager::printFileInfo(const char* name) const {
    for (size_t i = 0; i < numOfFiles; i++) {
        if (strcmp(files[i].getName(), name) == 0) {
            std::cout << PRINT_NAME << files[i].getName() << std::endl;
            std::cout << SIZE << files[i].getSize() << std::endl;
            std::cout << CREATION_TIME;
            files[i].getCreationTime().print();
            files[i].getCreationDate().print();
            std::cout << LAST_MODIFICATION_TIME;
            files[i].getLastModificationTime().print();
            files[i].getLastModificationDate().print();
            std::cout << ACCESS_RIGHTS << files[i].getAccessRights() << std::endl;
            std::cout << std::endl;
            return;
        }
    }
    std::cout << FILE_NAME_NOT_FOUND << std::endl;
}

void TextFileManager::print()const {
    for (size_t i = 0; i < numOfFiles; i++) {
        std::cout << files[i].getName() << std::endl;
    }
    std::cout << std::endl;
}

void TextFileManager::sort(SortOptions option) {
    switch (option) {
    case SortOptions::name: sortForName(); break;
    case SortOptions::creationTime: sortForCreationTime(); break;
    case SortOptions::modificationTime: sortForModificationTime(); break;
    case SortOptions::size: sortForSize(); break;
    }
}

void TextFileManager::sortForName() {
    for (int i = 0; i < numOfFiles-1; i++) {
        bool hasSwaps = false;

        for (int j = 0; j < numOfFiles - i-1; j++) {
            if (strcmp(files[j].getName(),files[j+1].getName())>0) {
                swapFiles(files[j], files[j + 1]);
                hasSwaps = true;
            }
        }

        if (!hasSwaps) {
            break;
        }
    }
}
void TextFileManager::sortForCreationTime() {
    for (size_t i = 0; i < numOfFiles-1 ; i++) {
        bool hasSwaps = false;

        for (size_t j = 0; j < numOfFiles -i -1 ; j++) {
            int comparisonBetweenDate=files[j].getCreationDate().compare(files[j + 1].getCreationDate());
            if (comparisonBetweenDate>0) {
                swapFiles(files[j], files[j + 1]);
                hasSwaps = true;
            }
            else if (comparisonBetweenDate == 0) {
                int comparisonBetweenTime = files[j].getCreationTime().compare(files[j + 1].getCreationTime());
                if (comparisonBetweenDate > 0) {
                    swapFiles(files[j], files[j + 1]);
                }
            }
        }

        if (!hasSwaps) {
            break;
        }
    }
}

void TextFileManager::sortForModificationTime() {
    for (size_t i = 0; i < numOfFiles-1; i++) {
        bool hasSwaps = false;

        for (size_t j = 0; j < numOfFiles - i-1; j++) {
            int comparisonBetweenDate = files[j].getLastModificationDate().compare(files[j + 1].getLastModificationDate());
            if (comparisonBetweenDate > 0) {
                swapFiles(files[j], files[j + 1]);
                hasSwaps = true;
            }
            else if (comparisonBetweenDate == 0) {
                int comparisonBetweenTime = files[j].getLastModificationTime().compare(files[j + 1].getLastModificationTime());
                if (comparisonBetweenTime > 0) {
                    swapFiles(files[j], files[j + 1]);
                }
            }
        }

        if (!hasSwaps) {
            break;
        }
    }
}

void TextFileManager::sortForSize() {
    for (size_t i = 0; i < numOfFiles-1; i++) {
        bool hasSwaps = false;

        for (size_t j = 0; j < numOfFiles - i-1; j++) {
            if (files[j].getSize() > files[j + 1].getSize()) {
                swapFiles(files[j], files[j + 1]);
                hasSwaps = true;
            }
        }

        if (!hasSwaps) {
            break;
        }
    }
}

TextFileManager::~TextFileManager() {
    free();
}