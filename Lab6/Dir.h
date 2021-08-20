#pragma once
#include "Element.h"
#include <vector>

class Dir: public Element {
  public:
  Dir(const std::string name): Element(name) {}
  ~Dir();

  void operator+=(Element *file);
  void print(const int spaces) const;
  Dir *findDir(const std::string name);
  void add(Element * el);
  const Element *get(const std::string name);

  private:
  std::vector<Element *> _files;  
};

std::ostream& operator<<(std::ostream& os, const Element & directories);