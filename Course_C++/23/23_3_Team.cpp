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

class Team{
    string name;
    int wins;;
public:
    Team(const string& n = "teamX", int w = 0) : name(n) , wins(w){}
    Team& operator+=(const Team& rhs){
        wins += rhs.wins;
        return *this;
    }
    friend Team operator+(Team a, const Team& b){
        a += b;
        return a;
    }
    friend bool operator==(const Team& a, const Team& b){
        return (a.name == b.name);
    }
    friend bool operator!=(const Team& a, const Team& b){
        return !(a == b);
    }
    friend ostream& operator<<(ostream& os, const Team& a){
        os << a.name << "(" << a.wins << ")";
        return os;
    }
};

int main(){
    Stack<Team> s2;
    s2.push(Team("Twins", 10));
    s2.push(Team("Bears", 5));
    cout << "s2.top() : " << s2.top() << endl;
    s2.pop();
    cout << "s2.top() : " << s2.top() << endl;
    s2.pop();
    s2.pop();
    return 0;
}