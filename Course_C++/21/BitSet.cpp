#include <iostream>
#include "BitSet.h"
using namespace std;

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
    if(v1.NBITS == v2.NBITS){
        for(int i = 0; i < v1.len; i++){
            tmp.u_m[i] = v1.u_m[i] | v2.u_m[i];
        }
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



int main(int argc, char *argv[]){
    BitSet b1(131), b2(131);
    b1.insert(3); b1.insert(5); b1.insert(8);
    b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
    b1.print(); b2.print();
    cout << "b1 = " << b1 << endl;
    cout << "b2 = " << b2 << endl;
    cout << "b1+b2= " << b1 + b2 << endl;
}