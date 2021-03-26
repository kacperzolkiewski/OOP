#pragma once
#include <iostream>

class Fun{
  public:
    double virtual wartosc(double n) {return n;};
    double operator()(double x) {return this->wartosc(x);}
};