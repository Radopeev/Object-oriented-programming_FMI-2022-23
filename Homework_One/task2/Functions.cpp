#include<cstring>
#include<iostream>
#include"Constants.h"
#include"Functions.h"
using namespace GlobalConstants;

int textFormatValidator(const char* name) {
    char format[MAX_FORMAT_SYMBOLS]="";
    int j = 0, size_t ,i = strlen(name) - 3;
    while (i < strlen(name)) {
        format[j++] = name[i++];
    }
    return strcmp(format, "txt");
}

char* concatenate(const char* str1, const char* str2)
{
    size_t resultLength = strlen(str1) + strlen(str2), i = 0;
    char* result = new char[resultLength + 1];
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    size_t j = 0;
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[resultLength] = '\0';
    return result;
}
