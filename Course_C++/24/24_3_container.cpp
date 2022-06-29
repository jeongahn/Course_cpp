#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

template <class T>
void print_container(const T& container, string s = ""){
    cout << s << "(" << container.size() << ")";
    auto it = container.begin();
    for(; it != container.end(); it++) cout << it << " ";
    cout << endl;
}

