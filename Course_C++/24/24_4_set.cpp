#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> myset; // myset은 중복 허용 x
    set<int>::iterator it;

    // set some initial values;
    for(int i = 1; i <= 5; i++){
        myset.insert(i*10);
    }
    it = myset.find(20);
    myset.erase(20); // == myset.erase(it);
    myset.erase(myset.find(40));
    cout << "myset contains: ";
    for(it = myset.begin(); it!=myset.end(); ++it){
        cout << ' ' << *it;
    }
    cout << '\n';
    myset.clear();
    for(int i = 1; i < 10; i++){
        myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
    }
    it = myset.begin();
    ++it;

    myset.erase(it); //erase(20)
    myset.erase(40); // 10 30 50 60 70 80 90

    it = myset.find(60); 
    myset.erase(it, myset.end()); // 10 30 50
    cout << "myset contains: ";
    for(it = myset.begin(); it != myset.end(); ++it){
        cout << ' ' << *it;
    }
    cout << '\n';

    myset.clear();
    //set::count -> count elements with a specific value
    for(int i = 1; i < 5; ++i) myset.insert(i * 3);
    for(int i = 0; i < 10; ++i){
        cout << i;
        if(myset.count(i)!= 0){
            cout << " is an element of myset.\n";
        }else{
            cout << " is not an element of myset.\n";
        }
    }
    
    //multiset & count
    int myints[] = {10, 73, 12, 22, 73, 73, 12};
    multiset<int> mymultiset (myints,myints+7); // 10부터 12까지 정렬되어서 넣어진다
    cout << "73 appears " << mymultiset.count(73) << " times in mymultiset.\n";

    return 0;
}