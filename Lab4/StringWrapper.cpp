#include "StringWrapper.h"

StringWrapper::StringWrapper(const char *str) {
    _str = new char[strlen(str) + 1];
    strcpy(_str, str);
}

StringWrapper::~StringWrapper() {
    delete [] _str;
}