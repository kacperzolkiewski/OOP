#pragma once
#include <iostream>
#include <utility>
#include <string.h>


class MyString {
    friend class Node;
    friend std::ostream& operator<<(std::ostream& s,const MyString &);
    public:
    MyString();
    MyString(const char *);
    MyString(const MyString &);
    MyString(MyString &&);
    ~MyString();
    int size() const;
    int fragments() const;
    const MyString fragment(int) const;
    void operator+=(const char *);
    void operator+=(MyString &&);
    void operator=(MyString &&);
    void add(const char *);
    const char *str() const {return _str;}
    void clear();

    private:
    MyString *_next;
    char *_str;
    int _size;
    int _fragments;
};

inline std::ostream& operator<<(std::ostream& s, const MyString &str) {
    if(str._str != nullptr) {
        s << str._str;
        MyString *temp = str._next;

        while(temp != nullptr) {
            s  <<  temp->_str;
            temp = temp->_next;
        }
        delete temp;
        return s;
    }

    return s;
}