#pragma once
#include <iostream>
#include "Element.h"

class File: public Element {
  public:
  File(const std::string name): Element(name) {}
  void print(const int spaces) const;

  private:

};