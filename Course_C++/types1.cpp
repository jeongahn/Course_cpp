#include <iostream>
using namespace std;

int main(){
	char c = 'a';
	int i = 97;
	float f = 97.0;
	double d = 97.0;
	char a[10]  = "abcde"; // char a[10] = {'a','b','c','d','e'};
	int b[10] = {0};
	//sizeof()라는 operator는 괄호안에 타입이름이나 변수이름을 받아서 
	//그것이 메모리에서 몇바이트를 차지하는지 표현해주는 연산자
	cout << "sizeof(char) is " << sizeof(char) <<endl;
	cout << "sizeof(c) is " << sizeof(c) <<endl;

	cout << "sizeof(int) is " << sizeof(int) <<endl;
	cout << "sizeof(i) is " << sizeof(i) <<endl;

	cout << "sizeof(float) is " << sizeof(float) <<endl;
	cout << "sizeof(f) is " << sizeof(f) <<endl;

	cout << "sizeof(double) is " << sizeof(double) <<endl;
	cout << "sizeof(d) is " << sizeof(d) <<endl;

	cout << "sizeof(a) is " << sizeof(a) <<endl;
	cout << "sizeof(b) is " << sizeof(b) <<endl;// int 10개 -> 40바이트
	

}