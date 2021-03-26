#pragma once
#include <iostream>
#include "Fun.h"

class Liniowa: public Fun{
    public:
        static Liniowa* utworz() {return new Liniowa;}
        Liniowa* a(double x) {_a = x; return this;};
        Liniowa* b(double y) {_b = y; return this;};
        double wartosc(double n) {return n*_a + _b;};
    private:
        double _a;
        double _b;
};

class Kwadratowa: public Fun{
    public:
        static Kwadratowa* utworz() {return new Kwadratowa;}
        Kwadratowa* a(double x) {_a = x; return this;};
        Kwadratowa* b(double y) {_b = y; return this;};
        Kwadratowa* c(double z) {_c = z; return this;};
        double wartosc(double n) {return n*n*_a + n*_b + _c;}
    private:
        double _a;
        double _b;
        double _c;
};