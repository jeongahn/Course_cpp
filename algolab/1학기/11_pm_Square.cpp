#include <iostream>

using namespace std;

//정사각형출력 -3

int main(){
	int t, n;

	cin >> t;

	for(int i = 0; i< t; i++){
		cin >> n;
		for(int j = 1; j <= n; j++){
			for(int r = 1; r <= n; r++){
				if(j == 1 || j == n || j == (n/2)+1){
					if(j == (n/2) + 1 && r == (n/2) + 1){
						cout << "+";
					}else if(r == 1 || r == n || r == (n/2) + 1){
						cout << "*";
					}else{
						cout << "+";
					}
				}else{
					if(r == 1 || r == n || r == (n/2) + 1){
						cout << "|";
					}else if(j == r ){
						cout << "\\";
					}else if(j + r == n + 1){
						cout << "/";
					}else{
						cout << ".";
					}
				}
			}
			cout << endl;
		}
	}
	return 0;
}
