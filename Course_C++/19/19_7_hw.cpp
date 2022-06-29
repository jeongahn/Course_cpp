#include <iostream>
#define NDEBUG
using namespace std;

class Kvector{
    int *m;
    int len;
public:
    Kvector(int sz = 0, int value = 0);
    Kvector(const Kvector& v);
    ~Kvector(){
        cout << this << " : ~Kvector() \n";
        delete[] m;
    }
    void print() const{
        for(int i = 0; i < len; i++){
            cout << m[i] << " ";
        }
        cout << endl;
    }
    void clear(){
        delete[] m;
        m = NULL;
        len = 0;
    }
    int size() const{
        return len;
    }
    Kvector& operator=(const Kvector& s);
    friend bool operator==(const Kvector& s1, const Kvector& s2);
    friend bool operator!=(const Kvector& s1, const Kvector& s2);
    int& operator[](int idx);
    const int operator[](int idx) const;
    friend ostream& operator<<(ostream& os, const Kvector& s);
    const bool compare(const Kvector& s1) const;
    

};
Kvector::Kvector(int sz,int value){
    len = sz;
    if(sz==0){
        m=NULL;
        return;
    }
    m = new int[sz];
    for(int i=0;i<len;i++){
        m[i] = value;
    }
    cout<<this<<" : "<<"Kvector(int, int)"<<endl;
}
Kvector::Kvector(const Kvector& v){
    m = new int[v.len];
    len = v.len;
    for(int i=0;i<len;i++){
        m[i] = v.m[i];
    }
    cout<<this<<" : "<<"Kvector(Kvector&)"<<endl;

}
Kvector& Kvector::operator=(const Kvector& s){
    len = s.len;
    m = new int[len];
    for(int i=0;i<len;i++)m[i]=s.m[i];
    return *this;
}
const bool Kvector::compare(const Kvector& s1) const{
    int count = 0;
    for(int i = 0; i < s1.size(); i++){
        if(m[i] == s1.m[i]){
            count++;
        }
    }
    if(count == s1.len){
        return true;
    }else{
        return false;
    }
}

bool operator==(const Kvector& s1, const Kvector& s2){
    if(s1.len == s2.len){
        if(s1.compare(s2) == true){
            return true;
        }
    }else{
        return false;
    }
}
bool operator!=(const Kvector& s1, const Kvector& s2){
    return !(s1 == s2);
}
int& Kvector::operator[](int idx){
    assert(0 <= idx && idx < size());
    return m[idx];
}
const int Kvector::operator[](int idx) const{
    assert(0 <= idx && idx < size());
    return m[idx];
}
ostream& operator<<(ostream& os, const Kvector& s){
    for(int i = 0; i<s.len; i++){
        os << s.m[i] << " ";
    }
    return os;

}

int main(){
    Kvector v1(3); v1.print();
    Kvector v2(2,9);v2.print();
    Kvector v3(v2); v3.print();
    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    return 0;
}
    
