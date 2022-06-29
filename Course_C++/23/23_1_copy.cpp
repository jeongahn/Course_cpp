#include <iostream>
using namespace std;

template<class T, class T2>
void copy(T1 a1[], T2 a2[], int n){
    for(int i = 0; i < n; i++)
        a1[i] = a2[i]
}
int main(){
    int v_i[5];
    double v_d[5] = {1.1,2.1,,3.1,4.1,5.1}

    copy(v_i, v_d, 5);
    for(int i = 0; i < 5; i++){
        cout << v_i[i] << endl;
    }
}