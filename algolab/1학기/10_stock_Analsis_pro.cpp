#include <iostream>

using namespace std;

int main(){
	int t, n;
	int num;
	cin >> t;
	for(int i =0; i < t; i++){
		int count = 0;
		int pre, tmp;

		cin >> n >> num;

		pre = num;
		cin >> num;
		tmp = num;

		for(int i = 2; i < n; i++){
			cin >> num;
			if(tmp > pre && tmp > num){
				count ++;
			}else if(tmp == num){
				continue;
			}
			pre = tmp;
			tmp = num;
		}
		cout << count << endl;
	}
	return 0;	
}
