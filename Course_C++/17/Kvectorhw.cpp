#include <iostream>
using namespace std;

class Kvector{
    int *m;
public:
    int len;
    Kvector(int sz = 0, int value = 0);
    Kvector(const Kvector& v);
    ~Kvector(){
        cout << this << " : ~Kvector() \n";
        delete[] m;
    }
    void print(){
        for(int i = 0; i < len; i++) cout << m[i] << " ";
        cout << endl;
    }
    void clear(){
        delete[] m;
        m = NULL;
        len = 0;
    }
    int size(){return len;}
};
Kvector::Kvector(int sz, int value){
    cout << this << " :  Kvector(int)\n";
    m = new int[sz];
    len = sz;
    for(int i = 0; i < sz; i++) m[i] = value;
}
Kvector::Kvector(const Kvector& v){
    cout << this << " : Kvector(Kvector&)\n";
    delete[] m;
    m = new int[v.len];
    len = v.len;
    for(int i = 0; i < len; i++) m[i] = v.m[i];
}
int main(){
    Kvector v1(3); v1.print();
    Kvector v2(2, 9); v2.print();
    Kvector v3(v2); v3.print();
    //Kvector vArray[3]; // 이건 2차원 배열이랑 같다;; 실수
    Kvector *v4 = new Kvector(); // 객체 pointer 변수에 동적 생성
    v4->len = 4; // 포인터 변수에만 -> 사용 가능 (*v4).len과 같다
    v4->print(); // 마찬가지 (*v4).print()와 같다.
    v2.clear();
    v2.print();
    v3.print();
    return 0;
}