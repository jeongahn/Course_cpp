#include <iostream>
using namespace std;

template<class T1, class T2>
class Box2{
    T1 data1;
    T2 data2;
public:
    Box2(){}
    void set1(T1 value){
        data1 = value;
    }
    void set2(T2 value){
        data2 = value;
    }
    T1 get1();
    T2 get2();
};
template<class T1, class T2>
T1 Box2<T1, T2>::get1(){return data1;}
template<class T1, class T2>
T2 Box2<T1, T2>::get2(){return data2;}

int main(){
    Box2<int, double> b;
    b.set1(100);
    b.set2(3.14);
    cout << b.get1() << "," << b.get2() << endl;
    return 0;
}