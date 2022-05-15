#include <iostream>
#include <cstdlib>
using namespace std;

void print(int *a){
	srand(100);
	int size = 5;
	int i = 0;
	while(size >= 0){
		if(rand() %  2 != 0){
			a[i] = rand();
			i++;
			size--;
		}
	}
	for(int i = 0; i < 5; i++){
		cout << a[i] << " ";
	}
	cout << endl;

}
int *makepointer(int n){
	int size = n;
	int *arr = new int[size];
	return arr;
}
int main(){
	int *ip;
	int n = 5;
	ip = makepointer(n);
	print(ip);
	delete[] ip;
}