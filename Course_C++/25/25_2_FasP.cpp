#include <iostream>
using namespace std;
#define N 10
void foo(){
    cout << "foo\n";
}
void bar(){
    cout << "bar\n";
}
void f(int i, void (*f1)(), void (*f2)()){
    if(i > 0) f1(); 
    else f2();
}
void my_int_func(int x){
    cout << x << endl;
}
int compare(const void *first, const void *second){
    int v1 = *(int *)first;
    int v2 = *(int *)second;
    if(v1 < v2) return -1;
    if(v1 > v2) return 1;
    return 0;
}

int main(){
    int i;

    cout << "enter a number : ";
    cin >> i;

    f(i, foo, bar);

    void(*foo1)(int);
    foo1 = my_int_func;
    foo1(2); // (*foo1)(2) 도 가능하다

    int a[N];
    for(i = 0; i < N; i++){
        a[i] = N - i;
    }
    for(i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;

    qsort(a, N, sizeof(int), compare);
    for(i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}