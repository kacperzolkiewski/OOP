#pragma once
#include "Clone.h"

//Szabon klasy dziedziczącej po funkcji Clone przetrzymujący obiekt
template <typename T>
class TemplatedClone: public Clone {
  public:
  // Konstruktor zapisujący obiect do naszej klasy
  TemplatedClone(const T &obiect): _obiect(obiect) {}

  // destruktor domyślny
  ~TemplatedClone() = default;

  // funkcja dzięki której mamy dostęp do naszego prywatnego obiektu
  T& getObiect() {return _obiect;}

  private:
  T _obiect;
};