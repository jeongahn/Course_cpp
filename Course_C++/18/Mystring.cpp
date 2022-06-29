#include <iostream>
#include <cstring>

using namespace std;

class MyString{
    char *p;
public:
    MyString(const char *str = NULL);
    MyString(char *str = NULL);
    MyString(const MyString& s);
    ~MyString(){delete[] p;}
    void print() const {cout << p << endl;}
    int size() const {return strlen(p);}
};
MyString::MyString(const char *str){
    if(!str){
        p = new char[1];
        p[0] = '\0';
        return;
    }
    p = new char[strlen(str) + 1];
    strcpy(p, str);
    cout << this << " " << str << "] MyString(const char *) \n";
}
MyString::MyString(char *str):p(str){//멤버 변수가 하나이기때문에 p(str) 이 없어도 상관없지만 명시적으로 보여주는게 더 좋은거 같다.
    cout << this << " " << str << "] MyString(char *) \n";
}
MyString::MyString(const MyString& s){
    p = new char[s.size() + 1];
    strcpy(p, s.p);
    cout << this << " " << s.p << "] MyString(const MyString&)\n";
}

int main(){
    const MyString s1("const");
    MyString s2("C++");
    MyString s3(s1);
    s1.print();
    s2.print();
    s3.print();

    return 0;
}