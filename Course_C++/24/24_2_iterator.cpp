#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define N 3

template <class T>
void print_vector(vector<T> v, string s= ""){
    //cout << s << "(" << v.size() << ")";
    auto it = v.begin();
    for(; it != v.end(); it++) cout << *it << " ";
    //for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
}


int main(){
    // vector<int> v1(N, 5);
    // print_vector(v1, "v1= ");
    // vector<int>::iterator it = v1.begin();
    // for(; it != v1.end(); it++) *it = 10; //* indirection operator는 iterator clas에서 오버로딩이 되어 마치 포인터의 역참조처럼 보인다.? 질문
    // print_vector(v1, "v1= ");
    
    // cout << "---------------------\n";

    // vector<int> myvector(5);
    // int i = 0;

    // vector<int>::reverse_iterator rit = myvector.rbegin();
    // for(; rit != myvector.rend(); rit++){
    //     *rit = ++i;
    // }
    // cout << "myvector contains";
    // for(vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it){
    //     cout << " " << *it;
    // }
    // cout << "\n";
    // cout <<"-----------------------\n";

    vector<char> v(3, 'x');
    print_vector(v,"15. v= ");
    char a[] = {'a', 'b', 'c', 'd', 'e'};
    vector<char>::iterator it;
    it = v.insert(v.begin(), 'p');
    print_vector(v, "19. v = ");
    cout << "return value points " << *it << endl;
    it = v.insert(v.end(), 2, 'z');
    print_vector(v, "22. v = ");
    cout << "return value points " << *it << endl;
    it = v.insert(v.begin(), &a[0], &a[2]);
    print_vector(v, "25. v = ");
    cout << "return value points " << *it << endl;
    it = v.insert(v.begin()+1,'*');
    print_vector(v, "28. v= ");
    cout << "return value points " << *it << endl;
    it = v.erase(v.begin());
    print_vector(v, "31. v= ");
    cout << "return value points " << *it << endl;
    it = v.erase(v.begin() + 3, v.end()- 1);
    print_vector(v, "34. v = ");
    cout << "return value points " << *it << endl;
    return 0;

}

