#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <list>
#include <set>
#include <map>
#include <functional>
using namespace std;


template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p){
    os << "[" << p.first << "]" << p.second;
    return os;
}

template <class T>
struct my_greater{
    bool operator()(T a, T b){
        return (a > b);
    }
};
template <class T>
void print_container(const T& container, string s = ""){
    cout << s << "(" << container.size() << ") ";
    auto it = container.begin();
    for(; it != container.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


template <class F>
bool my_f(int a, int b, F func){
    return func(a, b);
}

int main(){
    int i = 2, j = 1;
    bool r;
    my_greater<int> m;
    greater<int> g;
    bool r1;
    r = m(i, j);
    r1 = g(i, j); // 같다
    cout << r << endl; // -> true이기 때문에 1 출력
    r = my_f(i, j, m);
    cout << r << endl; // 마찬가지로 1출력
    r = my_f(i, j, my_greater<int>()); // 이거도 1출력 저렇게 하면 임시 객체가 생성되기 때문에 더 쓰기 좋다
    r1 = my_f(i, j, greater<int>()); // 생성자 호출 꼭 괄호 써야한다 임시 객체 생성 위해서 but template parameter경우는 괄호 x
    cout << r << endl;

    char a[10] = {'c', 'a', 'x', 'a', 'c', 'b', 'x', 'c', 'b', 'y'};

    set<char> s1(&a[0], &a[10]);
    map<int, char> m1;
    for(int i = 0; i < 10; i++){
        m1[i] = a[1];
    }

    set<char, greater<char>> s2(&a[0], &a[10]);
    map<int, char, greater<int>> m2;
    for(int i = 0; i < 10; i++) m2[i] = a[i];

    print_container(s1, "s= ");
    print_container(s2, "s2= ");
    print_container(m1, "m= ");
    print_container(m2, "m2= ");
    
}