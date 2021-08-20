#pragma once
#include <string>
#include <iostream>

struct Member {
  Member(const std::string& n) : m_name(n) {}
  const std::string& name() const { return m_name; }
  Member& power(int p) { m_power = p; return *this; }
  Member& magic(int p) { m_magic = p; return *this; }
  Member& health(int p) { m_health = p; return *this; }
  int power() const { return m_power; }
  int magic() const { return m_magic; }
  int health() const { return m_health; }
  bool operator<(const Member& other) const {return m_name < other.m_name;}
  
  std::string m_name;
  int m_power;
  int m_magic;
  int m_health;
};


inline std::ostream& operator<<(std::ostream& o, const Member& m) {
  o << m.name()
    << " power:" << m.power()
    << " magic:" << m.magic()
    << " health:" << m.health();
  return o;
}

struct Comparison {
  bool operator()(const Member &mem1, const Member &mem2) {
    return mem1.name() < mem2.name() ? true : false; 
  }
};
