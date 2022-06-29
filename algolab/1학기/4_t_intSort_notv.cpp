#include <iostream>

#include <algorithm>
using namespace std;

int main(){
	
	int t;
	int n;
	cin >> t;
	for(int i = 0 ; i < t; i++){
		int arr[3];
		int tmp;
		for(int i = 0; i < 3; i++){
			cin >> arr[i];
		}
		for(int i = 0; i < 2; i++){
			for(int j = i + 1; j < 3; j++){
				if(arr[i] > arr[j]){
					tmp = arr[j];
					arr[j] = arr[i];
					arr[i] = tmp;
				}else if(arr[i] == arr[j]){
					continue;
				}
			}
		}
		for(int i = 0; i < 3; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
		
	}
}
