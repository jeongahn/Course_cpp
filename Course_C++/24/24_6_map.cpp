#include <iostream>
#include <map>
#include <string>

using namespace std;
int main(){
    //example 1
    map<char, string> mymap;

    mymap['a'] = "an element";
    mymap['b'] = "another element";
    mymap['c'] = mymap['b']; // value 대입연산

    cout << "mymap['a'] is " << mymap['a'] << '\n';
    cout << "mymap['b'] is " << mymap['b'] << '\n';
    cout << "mymap['c'] is " << mymap['c'] << '\n';
    cout << "mymap['d'] is " << mymap['d'] << '\n';

    cout << "mymap now contains " << mymap.size() << " element.\n";

    //example 2

    map<char, int> mymap2;

    mymap2['b'] = 100;
    mymap2['a'] = 200;
    mymap2['c'] = 300;

    for(auto it = mymap2.begin(); it != mymap2.end(); ++it){
        cout << (*it).first << " => " << it->second << '\n';
    }// iterator가 가리키는 원소의 첫번째 값인 key를 나타낸다
    // second는 value를 나타낸다 위에처럼 둘다 가능!

    //example 3

    multimap<char, int> mymultimap;
    multimap<char, int>::iterator mit;

    mymultimap.insert(pair<char, int>('a', 100));
    mymultimap.insert(pair<char, int>('z', 150));
    mymultimap.insert(pair<char, int>('b', 75));
    mymultimap.insert(pair<char, int>('c', 300));
    mymultimap.insert(pair<char, int>('a', 30));

    multimap<char, int>anothermultimap;
    anothermultimap.insert(mymultimap.begin(), mymultimap.find('c'));

    cout << "mymultimap contains:\n";
    for(mit = mymultimap.begin(); mit != mymultimap.end(); ++mit){
        cout << (*mit).first << " => " << (*mit).second << "\n";
    }
    cout << "anothermultimap contains:\n";
    for(mit = anothermultimap.begin(); mit!=anothermultimap.end(); ++mit){
        cout << (*mit).first << " => " << (*mit).second << '\n';
    }
    //example 4

    multimap<char,int> mymm;
     
    return 0;

}