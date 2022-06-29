#include <iostream>

using namespace std;

int main(){
	int t;
	int n, cal_Num;
	
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		int sum = 1;

		for(int j = 0; j < n; j++){
			cin >> cal_Num;
			sum *= cal_Num % 10;
			sum %= 10;
		}
		cout << sum <<endl;
	}

	return 0;
}
