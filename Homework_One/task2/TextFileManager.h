#pragma once
#include "File.h"
#include "Sort_Options.h"
#include "Functions.h"

class TextFileManager
{
private:
    File* files;
    int maxFiles;
    int numOfFiles = 0;

    void copyFrom(const TextFileManager& other);
    void free();

    void sortForName();
    void sortForCreationTime();
    void sortForModificationTime();
    void sortForSize();
    void swapFiles(File& a, File& b);

public:
    TextFileManager(size_t maxFiles);
    TextFileManager(const TextFileManager& other);
    TextFileManager& operator=(const TextFileManager& other);
    void addFile(const char* name,
        size_t hours, size_t min, size_t secs,
        size_t day, size_t month, size_t year, const char* accessRights);
    void editFile(const char* name, const char* change,
        size_t hours, size_t min, size_t secs,
        size_t day, size_t month, size_t year, char group);
    void addInFile(const char* name, const char* addition,
        size_t hours, size_t min, size_t secs,
        size_t day, size_t month, size_t year, char group);  
    void removeFile(const char* name);
    void changeRights(const char* name, char group, char newRight);    
    void printFile(const char* name, char group) const;
    void printFileInfo(const char* name) const;
    void print() const;
    void sort(SortOptions option);
    ~TextFileManager();
};

