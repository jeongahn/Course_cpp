#include <iostream>
#include "Avector.h"
#include "Bvector.h"
using namespace std;
int main(int argc, char *argv[]){
    Bvector b1(61), b2(131);
    b1.set(3); b1.set(5); b1.set(8);
    b2.set(4); b2.set(5); b2.set(8); b2.set(130);
    b1.print();
    b2.print();
    cout << "b1.size() : " << b1.size() << endl;
    cout << "b2.size() : " << b2.size() << endl;
}