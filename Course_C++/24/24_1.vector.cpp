#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define N 3
//using a print_vector() template function
template <class T>
void print_vector(vector<T> v, string s= ""){
    cout << s << "(" << v.size() << ")";
    for(int i = 0; i < v.size()l i++) cout << v[i] << " ";
    cout << "\n";
}

int main(){
    vector<int> v1;

    //empty vector 만들기
    cout << "v1.size() = " << v1.size() << endl;
    cout << "v1.max_size() = " << v1.max_size() << endl;
    cout << "v1.empty() = " << v1.empty() << endl;
    // error : cout << "v1[0] = " << v1[0] << endl; -> 원소가 없기 때문에 segmentation fault error

    //integer vector with size 3
    vector<int> v2(3);
    cout << "v2.size() = " << v2.size() << endl;
    cout << "v2.max_size() = " << v2.max_size() << endl;
    cout << "v2.empty() = " << v2.empty() << endl;
    cout << "v2.capacity() = " << v2.capacity() << endl;
    cout << "v2[0] = " << v2[0] << endl;

    //integer vector with size 3, initialized to 5s
    vector<int> v3(N, 5);
    cout << "v3.size() = " << v3.size() << endl;
    cout << "v3.max_size() = " << v3.max_size() << endl;
    cout << "v3.empty() = " << v3.empty() << endl;
    cout << "v3.capacity() = " << v3.capacity() << endl;
    cout << "v3[0] = ";
    for(int i = 0; i < N; i++) cout << v3[i] << " ";
    cout << endl;
    //error : using integer vector causing a run tine error
    v3[0] = 1;
    v3[1] = 2;
    v3[2] = 3;
    //error : v3[4] = 4; -> runtime error
    for(int i = 0; i < N; i++) cout << v3[i] << " ";
    cout << "\n";

    //resizing a vector
    v3.resize(5);
    cout << "v3.size() = " << v3.size() << endl;
    cout << "v3.max_size() = " << v3.max_size() << endl;
    cout << "v3.empty() = " << v3.empty() << endl;
    cout << "v3.capacity() = " << v3.capacity() << endl;
    cout << "v3[0] = ";
    v3[0] = 1;
    v3[1] = 2;
    v3[2] = 3;
    v3[4] = 4;
    for(int i = 0; i < N; i++) cout << v3[i] << " ";
    cout << "\n";

    //using a print_vector() template function
    vector<int> v4(3,5);
    print_vector(v4, "15. v4 : ");
    v4.resize(6);
    print_vector(v4, "17. v4 : ");
    v4[1] = 100; v4[5] = -1;
    v4.clear(); // 길이를 zero로 만들어준다
    print_vector(v4, "20. v4 : ");

    cout << "v4.front() = " << v4.front() << endl;
    cout << "v4.back() = " << v4.back() << endl;

    print_vector(v4, "21. v4 : ");
    v.push_back(100);
    print_vector(v4, "23. v4 : ");
    v.pop_back();
    print_vector(v4, "25. v4 : ");

    return 0;

}