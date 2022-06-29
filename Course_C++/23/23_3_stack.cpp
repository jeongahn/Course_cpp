#include <iostream>
using namespace std;

class StackFullException : public exception{};
class StackEmptyException : public exception{};

template<class T>
class Stack{
    T *s;
    int capacity, t;
public:
    Stack(int n = 100):capacity(n), t(-1){
        s = new T[capacity];
    }
    ~Stack(){delete[] s;}
    void push(const T& v){
        if (full()) throw StackFullException();
        s[++t] = v;
    }
    void pop(){
        if(empty()) throw StackEmptyException();
        --t;
    }
    T& top(){
        if(empty()) throw StackEmptyException();
        return s[t];
    }
    const T& top() const{
        if(empty()) throw StackEmptyException();
    }
    int size() const{return t + 1;}
    bool empty() const{return t == -1;}
    bool full() const{return t == capacity - 1;}
};

int main(int argc, char *argv[]){
    Stack<char> s1;
    cout << "s1.empty() : " << s1.empty() << endl;
    s1.push('a');
    s1.push('b');
    cout << "s1.empty() : " << s1.empty() << endl;
    cout << "s1.top() : " << s1.top() << endl;
    cout << "s1.top() : " << s1.top() << endl;
    s1.pop();
    cout <<  "s1.top() : " << s1.top() << endl;
    s1.pop();
     
    string str = argv[1];
    for(int i = 0; i < str.length(); i++) s1.push(str[i]);
    for(int i = 0; i < str.length(); i++, s1.pop()){
        if(s1.top() != str[i]){
            cout << str << " is not a palindrome. \n";
            break;
        }
    }
    if(s1.empty()){
        cout << str << " is a palindrome.\n";
    }
}