#include <iostream>
using namespace std;
#include "scope2-1.h"
#include "scope2-2.h"

int g1 = 3;
extern int garray[3]; 

int main() {
	extern int i;

	for(int j = 0; j < 2; j++){
		static int i = 1;
		i++;
		cout << "inside loop, i = " << i << endl;
	}
	cout  << "outside loop, i = " << i << endl;

	cout << "f1(i ) = " << f1(i) << endl;
	cout << "f1(i) = " << f1(1000, 50) << endl;
	f2();
	return 0;
}
int f1(int a, int b){
	static int c = 100;
	c = a + b + c + g1;
	return c;
}