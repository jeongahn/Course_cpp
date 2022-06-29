#include <iostream>
#include <set>
#include <map>
#include <functional>
using namespace std;

template <class Ta, class Tb>
ostream& operator<<(ostream& os, const pair< Ta, Tb >& p){
  os << "[" << p.first << "]" << p.second;
  return os;
}

int main(){
    string a[5] = {"0x4B", "0x20", "0x3A","0x1C","0x20"};

    multiset<string> ms(&a[0], &a[5]);  
  
    auto pit = ms.equal_range("0x20");
    for (auto it=pit.first; it!=pit.second; it++)
        cout << distance(ms.begin(), it) << endl;
        cout << *pit.second << '\n';
    // distance(it1, it2) 함수는 container 안에서 
    // 반복자 it2 가 가리키는 원소가 
    // 반복자 it1 가 가리키는 원소보다 
    // 몇개만큼 뒤에 있는지를 정수로 반환하는 함수임  
    map<int, string> m;
    for (int i=0; i<5; i++) 
        m[i] = a[i];
    for (auto it=m.find(3); it!=m.end(); it++) // upper_bound(3)도 가능
        cout << *it << endl;
    return 0;
}