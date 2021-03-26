#include "Algs.h"

Argumenty sq(Argumenty const& arg) {
  double sq = 0;
  sq = sqrt(arg[0]);
  Argumenty temp(1);
  temp(0, sq);
  return temp;
}

Argumenty sum(Argumenty const& arg) {
  int sum = 0;
  for(int i = 0; i < arg.getSize(); i++) {
      sum += arg[i];
  }
  Argumenty temp(1);
  temp(0, sum);
  return temp;
}

Argumenty minimum(Argumenty const& arg) {
  int min = arg[0];
  for(int i = 0; i < arg.getSize(); i++) {
    if(min >= arg[i])
      min = arg[i];
  }
  Argumenty temp(1);
  temp(0, min);
  return temp;
}

