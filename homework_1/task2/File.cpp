#include<iostream>
#include "File.h"
#pragma warning(disable:4996)


void File::setName(const char* name) {
    if (strlen(name) > MAX_NAME_SYMBOLS) {
        return;
    }
    else strcpy(this->name, name);
}

void File::setContent(const char* content) {
    if (strlen(content) > MAX_CONTENT_SYMBOLS) {
        return;
    }
    else strcpy(this->content, content);
}

void File::setSize() {
    size = strlen(content);
}


void File::setCreationTime(size_t hours, size_t min, size_t secs) {
    this->creationTime = Time(hours, min, secs);
}

void File::setCreationDate(size_t day, size_t month, size_t year) {
    this->creationDate = Date(day, month, year);
}

void File::setLastModificationTime(size_t hours, size_t min, size_t secs) {
    this->lastModificationTime = Time(hours, min, secs);
}
void File::setLastModificationDate(size_t day, size_t month, size_t year) {
    this->lastModificationDate = Date(day, month, year);
}

void File::setAccessRights(const char* accessRights) {
    if (strlen(accessRights) > MAX_ACCESS_RIGHTS_SYMBOLS) {
        return;
    }
    else strcpy(this->accessRights, accessRights);
}

const char* File::getName() const {
    return name;
}

const char* File::getContent() const {
    return content;
}

size_t File::getSize() const {
    return size;
}

const Time& File::getCreationTime() const {
    return creationTime;
}

const Date& File::getCreationDate() const {
    return creationDate;
}

const Time& File::getLastModificationTime() const {
    return lastModificationTime;
}

const Date& File::getLastModificationDate() const {
    return lastModificationDate;
}

const char* File::getAccessRights() const {
    return accessRights;
}

void File::changeRight(size_t indexForChange, char changeCharacter) {
    accessRights[indexForChange] = changeCharacter;
}

bool File::checkForSomeRight(char group, char rightCheck) const {
    if (group == USER_OWNER_CONST) {
        for (size_t i = 0; i < 3; i++) {
            if (accessRights[i] == rightCheck) return true;
        }
        return false;
    }
    else if (group == GROUP_OWNER_CONST) {
        for (size_t i = 3; i < 6; i++) {
            if (accessRights[i] == rightCheck) return true;
        }
        return false;
    }
    else if (group == OTHER_CONST) {
        for (size_t i = 6; i < 9; i++) {
            if (accessRights[i] == rightCheck) return true;
        }
        return false;
    }
}

void File::fileUpdate(const char* change,
    size_t hours, size_t mins, size_t secs,
    size_t day, size_t month, size_t year) {
    setContent(change);
    setSize();
    setLastModificationTime(hours, mins, secs);
    setLastModificationDate(day, month, year);

}

void File::changeRightByGroup(char group, char rightCheck) {
    if (group == USER_OWNER_CONST) {
        for (size_t i = 0; i < 3; i++) {
            if (accessRights[i] == rightCheck) accessRights[i] = '-';
            else if (accessRights[i] == '-') accessRights[i] = rightCheck;
        }
    }
    else if (group == GROUP_OWNER_CONST) {
        for (size_t i = 3; i < 6; i++) {
            if (accessRights[i] == rightCheck) accessRights[i] = '-';
            else if (accessRights[i] == '-') accessRights[i] = rightCheck;
        }
    }
    else if (group == OTHER_CONST) {
        for (size_t i = 6; i < 9; i++) {
            if (accessRights[i] == rightCheck) accessRights[i] = '-';
            else if (accessRights[i] == '-') accessRights[i] = rightCheck;
        }
    }
}