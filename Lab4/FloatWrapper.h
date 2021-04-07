#pragma once
#include "Wrapper.h"

class FloatWrapper: public Wrapper {
    public:
    FloatWrapper(float num): _value(num) {}
    void print() const {std::cout << " " << _value;}
    Wrapper *copy() {return new FloatWrapper(_value);}

    private:
    float _value;
};