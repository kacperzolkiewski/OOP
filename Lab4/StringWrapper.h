#pragma once
#include "Wrapper.h"

class StringWrapper: public Wrapper {
    public:
    StringWrapper(const char *);
    ~StringWrapper();
    void print() const {std::cout << " " << _str;}
    Wrapper *copy() {return new StringWrapper(_str);}

    private:
    char *_str;
};