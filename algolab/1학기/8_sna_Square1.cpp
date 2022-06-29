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
		int num = 1;
		// 2차원 배열
		for(int i = 0; i < n; i++){
			for(int j = 0; j<n;  j ++){
				sna_Square[i][j] = num;
				num ++;
			}
		}
		int r = 0;
		int c = -1;
		int p = 0;

		while(n > 0){
			for(int j = 0; j < n; j ++){
				c++;
				print_arr[p] = sna_Square[r][c];
				p++;
			}
			n--; //4, 2, 0
			for(int j = 0; j < n; j++){
				r++;
				print_arr[p] = sna_Square[r][c];
				p++;
			}
			for(int j = 0; j < n; j++){
				c--;
				print_arr[p] = sna_Square[r][c];
				p++;
			}
			n--; // 3, 1
			for(int j = 0; j < n; j++){
				r--;
				print_arr[p] = sna_Square[r][c];
				p++;
			}

		}

		for(int i = a; i < b+1; i++){
			cout << print_arr[i-1] << ' ';
		}

		cout << '\n';

	}
	return 0;
}
