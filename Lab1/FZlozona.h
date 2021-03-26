#pragma once
#include "Fun.h"
#include "Op.h"

class FZlozona: public Op1 {
    public:
        FZlozona(Fun * fun): _Fun(fun) {};
        double w(double n) {return _Fun->wartosc(_fun->wartosc(n));}
    private:
        Fun* _Fun;
};