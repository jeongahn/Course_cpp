#include <iostream>

using namespace std;

int main(void){
	int square[100][100];
	int t, n;
	int dir;

	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		int r = 1;  // 행
		int c = 1;  // 열
		int num;
		int count = n * n;
		
		if(n % 4 == 1){
			num = 0;
		}else if(n % 4 == 3){
			num = 1;
		}
		while(count){
			if(c - r == 1 && (n/2) + 1 >= r && c - 1!= (n/2) + 1 ){
				square[r][c] = num;
				r ++;
				if(num == 0){
					num = 1;
				}else if(num == 1){
					num = 0;
				}
			}else if(r == c && (n/2) + 1 >= r){
				dir  = 1;
				square[r][c] = num;
				r ++;
			}
			else if(r + c == n + 1 && r > c){
				dir = 2;
				square[r][c] = num;
				c ++;
			}else if(r == c && (n/2) + 1 < r){
				dir = 3;
				square[r][c] = num;
				r --;
			}else if(r + c == n + 1 && r < c){
				dir = 4;
				square[r][c] = num;
				c --;
			}else{
				square[r][c] = num;

				if(dir == 1){
					r ++;
				}else if(dir == 2){
					c ++;
				}else if(dir == 3){
					r --;
				}else if(dir == 4){
					c --;
				}
			}

			count --;
		}
		for(int i =1; i <= n; i ++){
			for(int j = 1; j <= n; j++){
				cout << square[i][j];
			}
			cout << '\n';
		}
		
	}
	return 0;
}
