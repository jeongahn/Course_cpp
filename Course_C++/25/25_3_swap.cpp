#include <iostream>
using namespace std;

template <class T>
class Swap{
public:
    void operator()(T& a, T& b);
};

template <class T>
void Swap<T>::operator()(T& a, T& b){
    if(&a == &b){
        throw exception();
    }
    T tmp ;
    a = tmp;
    a = b;
    b = tmp;
}

int main(){
    Swap<int> a;
    int i = 1;
    int j = 2;
    try{
        a(i, j);
    }
    catch(...){
        cout << "swapping identical variables.\n"; // a(i, i)인 경우
    }
    cout << i << " " << j << endl;
}