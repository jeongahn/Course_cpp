#include <iostream>
#include <exception>
#include "BitSet.h"
using namespace std;
/*
class IncompatibleException : public exception{
public:
    int a1;
    int a2;
    IncompatibleException(int a1, int a2){
        this->a1 = a1;
        this->a2 = a2;
    }
};*/

BitSet::BitSet(int sz) : Bvector(sz){}
void BitSet::insert(int v){
    if(v >= NBITS) return;
    unsigned int &element = u_m[v/32];
    int v_bit = v % 32;
    unsigned int mask = 1 << v_bit;
    element |= mask;
}
BitSet operator+(const BitSet& v1, const BitSet& v2){
    BitSet tmp(v1.NBITS);
    for(int i = 0; i < v1.len; i++){
        tmp.u_m[i] = v1.u_m[i] | v2.u_m[i];
    }
    return tmp;
}

ostream& operator<<(ostream& os, const BitSet& s){
    os << "{ ";
    for(int i = 0; i < s.NBITS; i++){
        if(s.bit(i) == 1){
            os << i << " ";
        }
    }
    os << "} ";
    return os;
}

void foo(){
    BitSet b1(132), b2(131);
    b1.insert(3); b1.insert(5); b1.insert(8);
    b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
    b1.print(); b2.print();
    cout << "b1 = " << b1 << endl;
    cout << "b2 = " << b2 << endl;
    try{
        if(b1.size() != b2.size()) throw IncompatibleException(b1.size(), b2.size());
        cout << "b1+b2= " << b1 + b2 << endl;
    }
    catch(...){
        cout << "b1+b2= ";
        throw;
    }
}


int main(int argc, char *argv[]){

    try{
        foo();
    }
    catch(IncompatibleException& e){
        cout << "In + operation, the operands are not compatible.\n";
        cout << "The size of the first BitSet is " << e.a1 << endl;
        cout << "The size of the second BitSet is " << e.a2 << endl;
    }
    return 0;
}