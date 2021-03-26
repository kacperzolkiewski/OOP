#pragma once
#include <iostream>
#include "Fun.h"

class Op1{
    public:
        virtual double w(double n) {return n;};
        virtual Op1* z(Fun* fun) {_fun = fun; return this;};
       // Op1 *operator()(Fun *fun) {_fun = fun; return this;}
    protected:
        Fun *_fun;
};