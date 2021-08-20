#include "Dir.h"

Dir::~Dir() {
  std::cout << "Deleting Dir: " << getName() << std::endl;
  for(unsigned i = 0; i < _files.size(); i++) {
    std::cout << "About to delete " << _files[i]->getName() << std::endl;
    delete _files[i];
  }
}

void Dir::operator+=(Element *file) {
  _files.push_back(file);
}

void Dir::print(const int spaces) const {
  for(int i = 0; i < spaces; i++) {
    std::cout << " ";
  }
  std::cout << getName() << " (DIR)" << std::endl;
  for(auto i: _files) {
    i->print(spaces + 1);
  }
}

Dir * Dir::findDir(const std::string name) {
  if(getName() == name) {
    return this;
  } else {
    for(auto i: _files){
      if(i->getName() == name) {
        return dynamic_cast<Dir*>(i);
      }
      if(dynamic_cast<Dir*>(i))
        return dynamic_cast<Dir*>(i)->findDir(name);
    }
  }
  return nullptr;
}

void Dir::add(Element *el) {
  *this += el;
}

const Element* Dir::get(const std::string name) {
  if(getName() == name)
    return this;
  for(auto i: _files) {
    if(i->getName() == name) {
      return i;
    }
    if(dynamic_cast<Dir*>(i))
      dynamic_cast<Dir*>(i)->get(name);
  }
  return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Element& directories) {
  directories.print(0);
  return os;
}