#include <iostream>
using namespace std;

int main(){
	int i = 97;
	int *p; //포인터 변수

	// p = 0x7fffffffde50; -> compile error!!
	p = &i;

	int *q = &i;

	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "sizeof(p) is " << sizeof(p) << endl;
	cout << "sizeof(int *) is " << sizeof(int *) << endl; // sizeof()안에는 type이 들어오는거도 가능, 여기선 integer 포인터 타입

	cout <<  "i =  " << i << endl;
	cout <<  "p =  " << *p << endl;
	cout <<  "q =  " << *q << endl;
	cout <<  "&i =  " << &i << endl;

	char c = 'a';
	
	char *ptr;

	ptr = &c;
	cout << "sizeof(char *) is  " << sizeof(char *) << endl;

	return 0;

}