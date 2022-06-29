#include <iostream>
using namespace std;

//1번 주어진 정수의 합 구하기 문제

int main(){

    int numTestCases;
    cin >> numTestCases;

    for(int i = 0; i < numTestCases; i++){
        int numData, data;
        int sum = 0;

        cin >> numData;
        for (int j = 0; j < numData; j++){
            cin >> data;
            sum += data;
        }

        cout << sum << endl;
    }
    return 0;

    /*
    My code
    int t;
    int n;
    int a, c;
    int arr[100];

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        int sum = 0;
        for(int j = 0; j < n; j++){
            cin >> a;
            sum += a;
        }
        arr[i] = sum;
        c++;

    }
    for(int i = 0; i < c; i++){
        cout << arr[i] << endl;
    }

    return 0;*/
}