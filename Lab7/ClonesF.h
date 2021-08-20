#pragma once
#include <iostream>
#include <vector>
#include "TemplatedClone.h"

class ClonesF {
  public:
  ClonesF() = default;
  // Destruktor  usuwający wszystkie clony z klasy
  ~ClonesF() {
    for(auto i: _obiects)
      delete i;
  }

  // szablon funkcji dodający obiekty do naszej klasy
  template <typename T>
  void add(const T &obiect) {
    auto newObiect = new TemplatedClone<T>(obiect);
    _obiects.push_back(newObiect);
  }

  // szablon funkcji klonujący obiekt naszej klasy pasujący do podanego typu przy wywołaniu
  template <typename T>
  const T& clone() const {
    for(auto i: _obiects){
      if(dynamic_cast<TemplatedClone<T>*>(i)){
        return dynamic_cast<TemplatedClone<T>*>(i)->getObiect();
      }
    }
  }

  // szablon funkcji zamieniający obiekt naszej klasy na podany obiekt
  template <typename T>
  void replace(const T &obiect) {
    for(auto &i: _obiects) {
      if(dynamic_cast<TemplatedClone<T>*>(i)) {
        delete i;
        i = new TemplatedClone<T>(obiect); 
      }
    }
  }

  private:
  std::vector<Clone *> _obiects;
};