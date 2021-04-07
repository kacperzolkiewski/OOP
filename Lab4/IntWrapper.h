#pragma once
#include "Wrapper.h"

class IntWrapper: public Wrapper {
    public:
    IntWrapper(int num): _value(num) {}
    void print() const {std::cout << " " << _value;}
    Wrapper *copy() {return new IntWrapper(_value);}

    private:
    int _value;
};