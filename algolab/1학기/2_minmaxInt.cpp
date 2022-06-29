#include <iostream>
using namespace std;


//2번 주어진 정수의 최대최소 구하기

int main(){
	int numTestCases;
	int arr[100];
	cin >> numTestCases;

	for(int i = 0; i < numTestCases; i++){
		
		int numData, data;
		
		cin >> numData;
		int num = 0;
		for(int j = 0; j <numData; j++){
			cin >> data;
			arr[j] = data;
			num ++;
		}
		int min = arr[0];
		int max = arr[0];
		

		for(int r = 0;  r < num; r++ ){
			if(min > arr[r]){
				min = arr[r];
			}
			if(max < arr[r]){
				max = arr[r];
			}
		}
		cout << max << " " << min << endl;

	}
	/*
	int t, n, min, max, input;

	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;

		for(int j = 0; j< n; j++){
			cin >> input;
			if(j == 0){
				min = input;
				max = input;
			}
			min = min > input ? input : min;
			max = max < input ? input : max;
		}

		cout << max << " " << min << endl;
	}
	*/
	return 0;
}
