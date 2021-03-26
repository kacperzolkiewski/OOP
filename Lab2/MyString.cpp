#include "MyString.h"

MyString::MyString():_size(0), _fragments(0) {};

MyString::MyString(const char *str): _next(nullptr), _fragments(1) {
    _size = strlen(str);
    _str = new char[strlen(str) + 1];
    strcpy(_str, str);
}

MyString::MyString(const MyString&) {}

MyString::MyString(MyString&& str): MyString(str._str){
    _size = str._size;
    _fragments = str._fragments;
    MyString *temp = str._next;
        while(temp->_next != nullptr) {
            add(temp->_str);
            temp = temp->_next;
        }
    add(temp->_str);
    str._str = nullptr;
    str._fragments = 0;
    str._size = 0;
    
};


MyString::~MyString() {
    clear();
    delete [] _str;
}


int MyString::size() const {
    return _size;
}

int MyString::fragments() const {
    return _fragments;
}

void MyString::operator+=(const char* str) {
    _size += strlen(str);
    _fragments++;
    add(str);
}


void MyString::operator+=(MyString && other) {
    _size += other._size;
    _fragments += other._fragments;
    _next = &other;
}

void MyString::operator=(MyString && r) {
    _size = r._size;
    _str = r._str;
    _next = r._next;
    _fragments = r._fragments;

    r._size = 0;
    r._str = nullptr;
    r._next = nullptr;
    r._fragments = 0;
}

const MyString MyString::fragment(int index) const{
    const MyString *temp = this;
    for(int i = 0; i < index ; i++) {
        temp = temp->_next;
    }

    return *temp;
}

void MyString::add(const char * str) {
    if(_next == nullptr) {
        _next = new MyString(str);
    } else {
        MyString *temp = _next;
        while(temp->_next != nullptr) {
            temp = temp->_next;
        }
        temp->_next = new MyString(str);
    }
} 

void MyString::clear() {
    if(_next == nullptr) {
        return;
    } else {
        MyString *curr = _next;
        MyString *next = nullptr;
        while(curr != nullptr) {
            next = curr->_next;
            delete curr;
            curr = next;
        }
    }
}


