#pragma once
#include "Date.h"
#include "Time.h"
#include "Constants.h"

using namespace GlobalConstants;
using namespace Errors;
using namespace PrintMessages;

class File {
private:
    char name[MAX_NAME_SYMBOLS] = "";
    char content[MAX_CONTENT_SYMBOLS] = "";
    size_t size = 0;
    Date creationDate;
    Time creationTime;
    Date lastModificationDate;
    Time lastModificationTime;
    char accessRights[MAX_ACCESS_RIGHTS_SYMBOLS];
public:
    File() {};

    void setName(const char* name);
    void setContent(const char* content);
    void setSize();
    void setCreationTime(size_t hours, size_t min, size_t secs);
    void setCreationDate(size_t day, size_t month, size_t year);
    void setLastModificationTime(size_t hours, size_t min, size_t secs);
    void setLastModificationDate(size_t day, size_t month, size_t year);
    void setAccessRights(const char* accessRights);

    const char* getName()const;
    const char* getContent() const;
    size_t getSize() const;
    const Time& getCreationTime()const;
    const Date& getCreationDate()const;
    const Time& getLastModificationTime()const;
    const Date& getLastModificationDate()const;
    const char* getAccessRights()const;

    void fileUpdate(const char* change,
        size_t hours, size_t mins, size_t secs,
        size_t day, size_t month, size_t year);
    void changeRight(size_t indexForChange, char changeCharacter);
    bool checkForSomeRight(char group, char rightCheck)const;
    void changeRightByGroup(char group, char rightCheck);


};