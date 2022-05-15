#include <iostream>

using namespace std;

int main(){
	int t, a, b, c, d;

	cin >> t;
	for(int i = 0; i < t; i++){
		int s_arr[100] = {};
		cin >> a >> b >> c >> d;
		int overlap = 0;
		int total = 0;
		for(int i = a; i < b; i++){
			s_arr[i] = 1;
		}
		for(int j = c; j < d; j++){
			if(s_arr[j] == 1){
				overlap += 1;
			}else{	
				s_arr[j] = 1;
			}
		}
		for(int i = 0; i < sizeof(s_arr)/sizeof(s_arr[0]); i++ ){
			if(s_arr[i] == 1){
				total +=1;
			}
		}
		cout << overlap << " " << total << endl;
	}	
	return 0;
}