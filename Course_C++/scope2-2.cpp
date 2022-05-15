// scope2.2.cpp
#include <iostream>
using namespace std;
#include "scope2-1.h"
#include "scope2-2.h"

int garray[3];
int i;

void f2(void){
	extern int g1;
	cout << "f1(g1, 20) = " << f1(g1, 20) << endl;
}