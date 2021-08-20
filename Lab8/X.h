#pragma once

class X {
  public:
  X(const std::string &name =""): m_name(name) {}
  virtual ~X() {
    std::cout << "Deletinx X " << m_name << std::endl;
  }

  virtual const std::string& name() const {return m_name;}
  protected:
  std::string m_name;
};

std::ostream& operator<<(std::ostream& os, const X &obiect) {
  return os << obiect.name();
}

class Y: public X {
  public:
  Y(const std::string &name = ""): X(name) {}
  ~Y() {
    std::cout << "Deleteing Y " << m_name << std::endl;
  }
};