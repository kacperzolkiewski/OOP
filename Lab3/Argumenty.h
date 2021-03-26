  
#pragma once

#include <iostream>
#include <string>
#include <vector>

class Argumenty{
public:
    friend std::ostream& operator<<(std::ostream& s, const Argumenty &);
    Argumenty(int n);

    Argumenty(const Argumenty &arg);

    ~Argumenty();
    
    Argumenty& operator()(int, double);

    Argumenty operator=(Argumenty arg);

    static Argumenty pojedynczy(double x) { return Argumenty(1)(0,x);}

    double operator[](int index) const {return _args[index];}

    int getSize() const {return _size;}
private:
    std::vector<double> _args;
    int _size;
};

inline std::ostream& operator<<(std::ostream& s, const Argumenty & arg) {
  for(int i = 0; i < arg.getSize(); i++) {
    s << arg[i] << " ";
  }
  return s;
}
