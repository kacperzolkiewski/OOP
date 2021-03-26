#pragma once
#include "Op.h"

class ProstaRozniczka: public Op1{
    public:
        ProstaRozniczka(double n): _h(n) {};
        double w(double n) {return (_fun->wartosc(n + _h) - _fun->wartosc(n-_h))/(2 * _h);}
       // double operator()(double n) {return (_fun->wartosc(n + _h) - _fun->wartosc(n-_h))/(2 * _h);}
    private:
        double _h;
};