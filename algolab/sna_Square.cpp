#include <iostream>

using namespace std;

int main(){
	int t, n;
	int dir;
	int  sna_Square[1000][1000];
	int print_arr[1000000];
	int a, b;
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		cin >> a >> b;
		int p = 1;
		int count = n*n;
		int num = 1;
		int r = 1;
		int c = 1;
		// 2차원 배열
		for(int i = 1; i <= n; i++){
			for(int j = 1; j<= n;  j ++){
				sna_Square[i][j] = num;
				num ++;
			}
		}

		while(count > 0){

			if(r-c == 1 && (n /2) + 1 >= r && c - 1 != (n/2) + 1){
				print_arr[p] = sna_Square[r][c];
				c ++;
			}else if(r == c && (n/2) + 1 >= r){
				dir  = 1;
				print_arr[p] = sna_Square[r][c];
				c ++;
			}
			else if(r + c == n + 1 && r < c){
				dir = 2;
				print_arr[p] = sna_Square[r][c];
				r ++;
			}else if(r == c && (n/2) + 1 < r){
				dir = 3;
				print_arr[p] = sna_Square[r][c];
				c --;
			}else if(r + c == n + 1 && r > c){
				dir = 4;
				print_arr[p] = sna_Square[r][c];
				r --;
			}else{
				print_arr[p] = sna_Square[r][c];

				if(dir == 1){
					c++;
				}else if(dir == 2){
					r++;
				}else if(dir == 3){
					c --;
				}else if(dir == 4){
					r --;
				}
			}
			p++;
			count --;
		}	

		for(int i = a; i < b+1; i++){
			cout << print_arr[i] << ' ';
		}

		cout << '\n';

	}
	return 0;
}