#include <iostream>
#include <cstdlib>
using namespace std;

//정사각형출력 -3

int main(){
	int t, size;

	cin >> t;

	for(int i = 0; i< t; i++){
		cin >> size;
		int x, y, radius = size/2;

		for(y = radius; y >= -radius; y--){
			for(x = -radius; x <= radius; x++){
				if(abs(y) == radius){
					if(abs(x) == radius || x == 0){
						cout << "+";
					}else{
						cout << "-";
					}
				}
				else if(y == 0){
					if(abs(x) == radius){
						cout <<"+";
					}else if(x == 0){
						cout << "*";
					}else{
						cout << "-";
					}
				}else{
					if(abs(x) == radius || x == 0){
						cout << "|";
					}
					else if(y == x){
						cout << "/";
					}else if(-y == x){
						cout << "\\";
					}else{
						cout << ".";
					}
				}
			}
			cout << endl;
		}

		
	}
}	
