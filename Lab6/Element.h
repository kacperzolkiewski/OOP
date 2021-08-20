#pragma once
#include <iostream>


class Element {
  public:
  Element(const std::string name): _name(name) {}
  virtual ~Element() = default;
  virtual void print(const int spaces) const = 0;
  std::string getName() const {return _name;}

  private:
  std::string _name;
};