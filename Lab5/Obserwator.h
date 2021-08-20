#pragma once
#include <iostream>

// funkcja bazowa przedstawiająca klasę Obserwator 
class Obserwator {
  public:
  // wirtualny domyślny destruktor
  virtual ~Obserwator() = default;

  //funkcja aktualizujaca dane w obserwatorach
  virtual void update(int) = 0;
};

// klasa, która dziedziczy po klasie Obserwator przechowująca sumę elementów
class ObserwatorLicznik: public Obserwator {
  public:
  // konstruktor ustawiający sumę na 0
  ObserwatorLicznik(): sum(0) {}

  // funkcja dodająca do sumy wartość x
  void update(int x) override { sum += x; }

  // funkcja umożliwiająca dostęp do prywatnej zmiennej sum
  int suma() const { return sum; }

  private:
  // zmienna integer przechowująca sumę
  int sum;
};

// klasa, która dziedziczy po Obserwator odpowiadająca za wypisywanie elementów jej podanych
class ObserwatorWypisywacz: public Obserwator {
  public:
  // domyślny konstruktor
  ObserwatorWypisywacz() = default;

  // funkcja wypisująca podane do niej dane
  void update(int x) override {std::cout << x << " ";}
};