#include <iostream>
using namespace std;

class Kvector{
protected:
    int *m;
    int len;
public:
    Kvector(int sz = 0, int value = 0):len(sz){
        cout << this << " : Kvector(" << sz << "," << value << ")\n";
        if(sz == 0){
            m = NULL;
            return;
        }
        m = new int[sz];
        for(int i = 0; i < sz; i++){
            m[i] = value;
        }

    }
    Kvector(const Kvector& v){
        cout << this << " : Kvector(* " << &v << ")\n";
        m = new int[v.len];
        len = v.len;
        if(len == 0){
            m = NULL;
            return;
        }
        for(int i = 0; i < len; i++){
            m[i] = v[i];
        }
    }
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
};
Kvector& Kvector::operator=(const Kvector& s){
    len = s.len;
    m = new int[len];
    for(int i=0;i<len;i++)m[i]=s.m[i];
    return *this;
}


bool operator==(const Kvector& s1, const Kvector& s2){
    if(s1.len!=s2.len){
        return false;
    }
    else{
        for(int i=0;i<s1.len;i++){
            if(s1.m[i]!=s2.m[i]){
                return false;
            }
        }
    }
    return true;
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

# define N 3

class Avector : public Kvector{
    char table[N];
public :
    Avector(int sz = 0, int v = 0, const char *t = "abc") : Kvector(sz, v){
        for(int i = 0; i < 3; i++){
            table[i] = t[i];
        }
        cout << this << " : " << "Avector(" << sz << "," << v << "," << t << ")\n";
    }
    void setTable(const char *t){
        for(int i = 0; i < 3; i++){
            table[i] = t[i];
        }
    }
    friend ostream& operator<<(ostream& os, const Avector& v);
};
ostream& operator<<(ostream& os, const Avector& v){
    for(int i = 0; i < v.len; i++){
        os << v.table[v.m[i] % 3] << " ";
    }
    return os;
}

int main(int argc, char *argv[]){
    if(argc != 2){
        cout << "usage : ./avector pqr\n";
        return -1;
    }
    Avector v1(3); v1.print();
    Avector v2(2, 1, "xyz"); v2.print();
    Avector v3(v2); v3.print();
    cout << "v1 == v2" << (v1 == v2) << endl;
    cout << "v3 == v2" << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << "v1 : " << v1 << endl;
    v1.print();
    cout << "v2 : " << v2 << endl;
    v2.print();
    cout << "v3 : " << v3 << endl;
    v3.print();
    cout << "v3 != v2" << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    v1.setTable(argv[1]);
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    v1.print();
    v2.print();
    v3.print();
    return 0;
}

