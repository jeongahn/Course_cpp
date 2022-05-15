#include <iostream>

using namespace std;

int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		int x, y, radius;
		cin >> n;
		radius = n/2;
		for(y = radius; y >= -radius; y--){
			for(x = -radius; x <= radius; x++){
				if(abs(x) % 2 ==0){
					cout << 0;
				}else if(abs(x) % 2 != 0){
					cout << 1;
				}else if(abs(y) % 2 == 0){
					cout << 0;
				}else if(abs(y) % 2 != 0){
					cout << 1;
				}
			}
			cout << endl;
		}
	}
}