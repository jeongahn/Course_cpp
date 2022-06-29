#include <iostream>
#include <set>
using namespace std;

typedef multiset<int>::iterator It;

int main(){
    set<int> myset;
    set<int>::iterator itlow, itup;

    //example 1
    for(int i = 1; i < 10; i++){
        myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
    }
    itlow = myset.lower_bound(30); // 30 , lower_bound(value) -> value보다 더 앞에 가지 않는 첫번째 원소
    itup = myset.upper_bound(60); // 70, upper_bound(value) -> value보다 뒤에 오는 첫번째를 가리킨다.
    
    myset.erase(itlow, itup); // 10 20 70 80 90

    cout << "myset contains: ";
    for(set<int>::iterator it = myset.begin(); it != myset.end(); ++it){
        cout << ' ' << *it;
    }
    cout << '\n';

    //example 2
    myset.clear();
    for(int i = 1; i < 10; i++){
        myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
    }

    itlow = myset.lower_bound(25); // 30
    itup = myset.upper_bound(65); // 70

    cout << "myset contains: ";
    for(set<int>::iterator it = myset.begin(); it != myset.end(); ++it){
        cout << ' ' << *it;
    }
    cout << '\n';
    
    //example 3
    myset.clear();
    for(int i = 1; i < 10; i++){
        myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
    }
    pair<set<int>::const_iterator, set<int>::const_iterator> ret;

    ret = myset.equal_range(30); //ret의 type == pair
    cout << "the lower bound points to: " << *ret.first << '\n'; //myset.lower_bound(30)와 같다
    //(*ret).first가 아닌 *(ret.first)이다
    cout << "the upper bound points to: " << *ret.second << '\n'; //myset.upper_bound(30)과 같다.

    //example 4
    myset.clear();
    for(int i=1; i <= 5; i++) myset.insert(i*10); // 10 20 30 40 50
    pair<set<int>::const_iterator, set<int>::const_iterator> ret2;
    ret2 = myset.equal_range(35);
    cout << "the lower bound points to: " << *ret2.first << '\n'; // 40
    cout << "the upper bound points to: " << *ret2.second << '\n'; // 40
    
    //example 5
    
    int myints[] = {77, 30, 16, 2, 30, 30};
    multiset<int> mymultiset (myints, myints+6); // 정렬되어 담긴다 - 2 16 30 30 30 77
    pair<It, It> ret3 = mymultiset.equal_range(30);

    mymultiset.erase(ret3.first, ret3.second); // 2 16 77
    cout << "mymultiset contains:";
    for(It it = mymultiset.begin(); it != mymultiset.end(); ++it){
        cout << ' ' << *it;
    }
    cout << '\n';

    return 0;
}
