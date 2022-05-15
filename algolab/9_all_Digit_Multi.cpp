#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		unsigned int n;
		cin >> n;
		unsigned int count;
		unsigned int sum; 
		while(n >9){
			count = n;
			sum = 1;
			while(count > 0){
				if(count % 10 == 0){
					count /= 10;
					continue;
				}else{
					sum *= count % 10;
				}
				count /= 10;	
			}
			n = sum;
		}

		cout << n << endl;
	}
	return 0;
}