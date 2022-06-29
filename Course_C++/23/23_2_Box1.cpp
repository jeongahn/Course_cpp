#include <iostream>
using namespace std;

template<class T>
class Box{
    T data;
public:
    Box(){}
    void set(T value){data = value;}
    T get(){return data;}
};
// 클래스 외부에 멤버 함수를 정의할 때
// template<class T>
// Box<T>::Box(){}
// tmplate<class T>
// void Box<T>::set(T value){data = value;}
// template<class T>
// T Box<T>::get(){return data;}

int main(){
    Box<int> b1;
    b1.set(100);
    cout << b1.get() << endl;

    Box<double> b2;
    b2.set(3.14);
    cout << b2.get() << endl;

    return 0;
}