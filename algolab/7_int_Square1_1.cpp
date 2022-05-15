#include <iostream>

using namespace std;

int main(void){
	int square[100][100];
	int t, n;

	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		int num;
		int count = n;

		if(n % 4 == 1){
			num = 0;
		}else if(n % 4 == 3){
			num = 1;
		}

		int r = 0;
		int c = -1;
		

		while(n > 0){
			for(int j = 0; j < n; j ++){
				c++;
				square[r][c] = num;
				
			}
			n--; //4, 2, 0
			for(int j = 0; j < n; j++){
				r++;
				square[r][c] = num;
				
			}
			for(int j = 0; j < n; j++){
				c--;
				square[r][c] = num;
				
			}
			n--; // 3, 1
			for(int j = 0; j < n; j++){
				r--;
				square[r][c] = num;
				
			}
			if(num == 0){
				num = 1;
			}else if(num == 1){
				num = 0;
			}

		}
		for(int i =0; i < count; i ++){
			for(int j = 0; j < count; j++){
				cout << square[i][j];
			}
			cout << '\n';
		}

		
	}
	return 0;
}