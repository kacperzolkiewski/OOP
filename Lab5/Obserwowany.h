#pragma once
#include <iostream>
#include <vector>
#include "Obserwator.h"

// Klasa bazowa przedstawiająca obiekt obserwowany przez obserwatora, czyli inny obiekt
class Obserwowany {
  public:
  // wirtualny domyślny destruktor
  virtual ~Obserwowany() = default;
  
  //vitrualna metoda dodająca kolejnego obserwatora który będzie przetwarzał dane obiektu obserwowanego
  virtual void dodajObserwatora(Obserwator *obserwator);

  //virtualna metoda dodająca dane do obserwatorów znajdujących się w tej klasie (aktualizujemy dane)
  virtual void noweDaneNadeszly(int val);

  private:
  // kontener przechowujący obserwatorów, którzy obserwują daną klasę
  std::vector<Obserwator *> _obserwatorzy;
};