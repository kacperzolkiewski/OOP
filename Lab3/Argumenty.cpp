#include "Argumenty.h"


Argumenty::Argumenty(int n): _size(n) {
  _args.reserve(_size);
}

Argumenty::Argumenty(const Argumenty &arg): _size(arg.getSize())
{
    for(int i = 0; i < _size; i++) {
      _args.push_back(arg[i]);
    }
}

Argumenty::~Argumenty()
{
    _size = 0;
}

Argumenty& Argumenty::operator() (int index, double value)
{
    _args[index] = value;
    return *this;
}

Argumenty Argumenty::operator=(Argumenty arg) 
{
  _size = arg.getSize();
  for(int i=0;i<_size;++i)
  {
      _args[i] = arg._args[i];
  }

  return *this;
}