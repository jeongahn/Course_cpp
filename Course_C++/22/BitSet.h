// BitSet.h
#include <iostream>
#include <exception>
#include "Bvector.h"

class BitSet : public Bvector{
    public:
        BitSet(int sz = 32);
void insert(int v);
friend BitSet operator+(const BitSet& v1, const BitSet& v2);
friend std::ostream& operator<<(std::ostream& os, const BitSet& s);
};
class IncompatibleException : public std::exception{
public:
    int a1;
    int a2;
    IncompatibleException(int a1, int a2){
        this->a1 = a1;
        this->a2 = a2;
    }
};