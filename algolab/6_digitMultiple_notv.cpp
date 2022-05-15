#include <iostream>
using namespace std;

int main(){
	int t, n, answer;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		int i_n = n;
		int compare = n;
		int size = 0;
		while(n > 0){
			n /= 10;
			size ++;
		}
		int sum = 0;
		for(int i = 0; i < size; i++){
			int num = 1;
			for(int j = 0; j < size; j++){
				num *= i_n%10;
			}
			i_n /= 10;
			sum += num;
		}
		if(sum == compare){
			answer = 1;
		}else{
			answer = 0;
		}
		cout << answer << endl;
	}
	return 0;
}