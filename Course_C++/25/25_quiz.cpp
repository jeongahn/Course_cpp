#include <iostream>
#include <string>
#include <set>
#include <map>
#include <functional>

using namespace std;

struct MyStringComp{
    bool operator()(const string& s1, const string& s2){
        if(s1.size() > s2.size()) return true;
        else if(s1.size() < s2.size()) return false;
        else if(s1 < s2) return true;
        else return false;
    }
};

template <class T>
void print_container(const T& container, string s = ""){
    cout << s << "(" << container.size() << ")";
    auto it = container.begin();
    for(; it != container.end(); it++) cout << *it << " ";
    cout << endl;
}
int main(){
    string a[5] = {"4B", "201", "3", "03C", "20"};

    multiset<string, greater<string>> ms1(&a[0], &a[5]);
    print_container(ms1);
    multiset<string, MyStringComp> ms2(&a[0], &a[5]);
    print_container(ms2);
}
