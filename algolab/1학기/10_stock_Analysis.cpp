#include <iostream>

using namespace std;

int main(){
	int t, n;
	int num;
	cin >> t;

	for(int i =0; i < t; i++){
		cin >> n;
		int a = 0;
		int b = 0;
		int count = 0;

		for(int i = 0; i < n; i++){
			cin >> num;
			if(i == 0){
				a = num;
				b = 0;
			}else if(i < n){
				if(num > a){
					if(num > b){
						a = num;
						b = num;
					}
				}else if(num == a){
					continue;
				}else if(num < a){
					if(num > b){
						a = num;
					}else if(num < b){
						count += 1;
						a = num;
						b = 0;
					}
				}
			}

		}
		cout << count << endl;
	}

	return 0;
}
