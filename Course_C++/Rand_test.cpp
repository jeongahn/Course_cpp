#include <iostream>
#include <cstdlib>
using namespace std;

void get_random (int n){
	int i;
	int a = 0;
	for(i = 0; i < n; i++){
		srand(a);
		cout << rand() << endl;
		a++;
	}
}

int main(){
	get_random(10);
	cout << endl << "RAND_MAX is " << RAND_MAX << endl;
	return 0;
}