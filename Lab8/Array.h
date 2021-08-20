#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <int siz, typename T>
class Array {
  public:
  Array(): m_size(siz) {
    m_tab = std::vector<T>(siz);
  }

  T& operator[](const int &index) {return m_tab[index];}
  const int size() const {return m_size;}

  private:
  std::vector<T> m_tab;
  int m_size;
};

template <int siz, typename T>
std::ostream& operator<<(std::ostream& os, Array<siz, T> &tab) {
  for(int i = 0; i < tab.size(); i++)
    os << tab[i] << " ";
  return os;  
}


template <int siz, typename T>
class Array<siz, T*> {
  public:
  Array(): m_size(siz) {
    m_tab = new T*[m_size];
    std::for_each(m_tab, m_tab + m_size, [](T*& i){i = nullptr;});
  }

  ~Array() {
    for(int i = 0; i < m_size; i++) {
        delete m_tab[i];
    }
    delete [] m_tab;
  }

  T *&operator[](const int &index) {
    return m_tab[index];
  }

  const int& size() const {return m_size;}

  private:
  int m_size;
  T** m_tab;
};

template <int siz, typename T>
std::ostream& operator<<(std::ostream& os, Array<siz, T*> &tab) {
  for(int i = 0; i < tab.size(); i++) {
    if(tab[i] != nullptr)
      os << *tab[i] << " ";
  }
  return os;  
}