#include "PArr.h"


PArr::PArr(int num): _size(num) {
    _tab = new Wrapper*[num];

    for(int i = 0; i < _size; i++) {
        _tab[i] = nullptr;
    }
}

PArr::PArr(PArr &&other): _size(other._size){
    _tab = other._tab;
    other._tab = nullptr;
    other._size = 0;
}

PArr::~PArr() {
    for(int i = 0; i < _size; i++) {
        delete _tab[i];
    }

    delete [] _tab;
}



Wrapper *&PArr::operator[](int index) {
    return _tab[index];
}

const Wrapper *PArr::operator[](int index) const {
    return _tab[index];
}

PArr& PArr::operator=(PArr &parr) {
    for(int i = 0; i < _size; i++) {
        delete _tab[i];
    }
    delete [] _tab;

    _size = parr._size;
    _tab = new Wrapper*[_size];
    for(int i = 0; i < _size; i++) {
        _tab[i] = parr[i]->copy();
    }

    return *this;
}