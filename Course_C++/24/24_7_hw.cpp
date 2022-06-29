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
void print_container(const T& container, string s = ""){
    cout << s << "(" << container.size() << ") ";
    auto it = container.begin();
    for(; it != container.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    char a[10] = {'c', 'a', 'x', 'a', 'c', 'b' ,'x', 'c', 'b', 'y'};
    vector<char> v;
    for(int i = 0; i < 10; i++){
        v.push_back(a[i]);
    }
    print_container(v, "v= ");
    deque<char> dq;//(v.begin(), v.end());
    for(int i = 0; i < 10; i++){
        dq.push_back(a[i]);
    }

    print_container(dq, "dq = ");
    list<char> li;//(dq.begin(), dq.end());
    for(int i = 0; i < 10; i++){
        li.push_back(a[i]);
    }
    print_container(li, "li = ");

    set<char> s;
    for(int i = 0; i < 10; i++){
        s.insert(a[i]);
    }
    print_container(s, "s = ");

    multiset<char> ss;
    for(int i = 0; i < 10; i++){
        ss.insert(a[i]);
    }
    print_container(ss, "ss = ");

    map<int, char> m;
    for(int i = 0; i < 10; i++){
        m[i] = a[i];
    }
    print_container(m, "m = ");

    multimap<int, char> mm;
    for(int i = 0; i < 10; i++){
        mm.insert(pair<int, char>(i, a[i]));
    }
    print_container(mm, "mm = ");
}