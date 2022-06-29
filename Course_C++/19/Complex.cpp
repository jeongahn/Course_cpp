#include <iostream>
using namespace std;
enum COMPLEX_PART {RE, IM};
class Complex{
    double re, im;
public:
    Complex(double r = 0, double i =0);
    operator double() const{return re;} // 변환 연산자 Complex -> double
    ~Complex(){}
    double real() {return re;}
    double imag() {return im;}
    Complex add(const Complex& c) const; // const 객체도 호출이 가능하고 이 함수안에서 객체의 멤버 변수의 값은 바뀌지 않기에 const memberfunction 선언
    friend Complex operator+(const Complex& c, const Complex& d);
    friend bool operator==(const Complex& c, const Complex& d);
    friend bool operator!=(const Complex& c, const Complex& d);
    Complex& operator=(const Complex&c);
    Complex& operator[](COMPLEX_PART idx){return (idx? im : re)};
    void print() const;
    friend ostream& operator<<(ostream& os, const Complex& c);
};
Complex &Complex::operator=(const Complex& c){
    re = c.re;
    im = c.im;
    return *this;
}
Complex operator+(const Complex& c, const Complex & d){
    Complex result(c.re + d.re, c.im + d.im);
    return result;
}
bool operator==(const Complex& c, const Complex& d){
    return ((c.re == d.re) && (c.im == d.im));
}
bool operator!=(const Complex& c, const Complex& d){
    return !(c==d);
}
ostream& operator <<(ostream& os, const Complex& c){
    os << c.re << " + " << c.im << "i ";
    return os;
}
Complex::Complex(double r, double i) : re(r), im(i){}
Complex Complex :: add(const Complex& c) const{
    Complex result(re + c.re, im + c.im);
    return result;
}
void Complex::print() const{
    cout << re << " + " << im << "i" << endl;
}


int main(){
    Complex x(1,3);
    Complex y(2,3), z;
    x = y;
    cout << &x << " " << &y << endl;
    x.print();
    y.print();
    z = x + y;
    z.print();
    cout << y << z << endl;
    cout << (x == y) << endl;
    return 0;
}


