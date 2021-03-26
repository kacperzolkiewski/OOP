#pragma once
#include <iostream>
#include <vector>
#include <functional>


class SekwencjaAlgorytmow {
  public:

  void add(std::function<Argumenty(Argumenty const &)> fun) {_tab.push_back(fun);}

  double procesuj(const Argumenty &arg) {
    Argumenty temp(arg);
    for(auto &i : _tab) {
      temp = i(temp);
    }
    return temp[0];
  }

  private:
  std::vector<std::function<Argumenty(Argumenty const &)>> _tab;
};