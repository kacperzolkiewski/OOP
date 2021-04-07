#pragma once
#include "Wrapper.h"


class PArr {
    friend std::ostream& operator<<(std::ostream &, const PArr &);
    public:
    PArr(int);
    PArr(PArr &&);
    ~PArr();
    Wrapper *&operator[](int);
    const Wrapper *operator[](int) const;
    PArr& operator=(PArr &);

    private:
    int _size;
    Wrapper **_tab;
};

inline std::ostream& operator<<(std::ostream &s, const PArr &parr) {
    for(int i = 0; i < parr._size; i++) {
        parr._tab[i]->print();
    }
    s << " ";
    return s;
}