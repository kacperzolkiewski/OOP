#include "Obserwowany.h"

void Obserwowany::dodajObserwatora(Obserwator *obserwator) {
  _obserwatorzy.push_back(obserwator);
}

void Obserwowany::noweDaneNadeszly(int val) {
  for(auto i : _obserwatorzy) {
    i->update(val);
  }
}