#include "MyComplex.h"
// Constructor
myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// Copy constructor
myComplex::myComplex(const myComplex& number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}
// Accessor functions
int myComplex::getRealPart() const
{
    return realPart;
}
int myComplex::getImaginaryPart() const
{
    return imaginaryPart;
}
// Mutator functions
void myComplex::setRealPart(int real)
{
    realPart = real;
}
void myComplex::setImaginaryPart(int imag)
{
    imaginaryPart = imag;
}
void myComplex::set(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// Overloaded binary operators
myComplex myComplex::operator +(const myComplex& number) const
{
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator +(int value) const
{
    return myComplex(value) + (*this);
}
myComplex operator +(int value, const myComplex& number)
{
    return number + value;
}
myComplex myComplex::operator -(const myComplex& number) const
{
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator -(int value) const
{
    return (*this) - myComplex(value);
}
myComplex operator -(int value, const myComplex& number)
{
    return -(number - value);
}
myComplex myComplex::operator *(const myComplex& number) const
{
    int newReal = (realPart * number.realPart) - (number.imaginaryPart * imaginaryPart);
    int newImag = (realPart * number.imaginaryPart) + (imaginaryPart * number.realPart);
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator *(int value) const
{
    return myComplex(value) * (*this);
}
myComplex operator *(int value, const myComplex& number) 
{
    return number * value;
}
// Assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator =(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}
myComplex& myComplex::operator +=(const myComplex& number)
{
    realPart += number.realPart;
    imaginaryPart += number.imaginaryPart; 
    return *this;
}
myComplex& myComplex::operator +=(int value)
{
    realPart += value;
    imaginaryPart += 0;
    return *this;
}
myComplex& myComplex::operator -=(const myComplex& number)
{
    realPart -= number.realPart;
    imaginaryPart -= number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator -=(int value)
{
    realPart -= value;
    imaginaryPart -= 0;
    return *this;
}
myComplex& myComplex::operator *=(const myComplex& number)
{
    int num_1 = (realPart * number.realPart) - (imaginaryPart * number.imaginaryPart);
    int num_2 = (realPart * number.imaginaryPart) + (imaginaryPart * number.realPart);
    realPart = num_1;
    imaginaryPart = num_2;
    return *this;
}
myComplex& myComplex::operator *=(int value)
{
    realPart *= value;
    imaginaryPart *= value;
    return *this;
}
// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const
{
    return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const
{
    return (realPart != number.realPart) || (imaginaryPart != number.imaginaryPart);
}

bool myComplex::operator >(const myComplex& number) const
{
    return norm() > number.norm();
}
bool myComplex::operator >=(const myComplex& number) const
{
    return norm() >= number.norm();
}
bool myComplex::operator <(const myComplex& number) const
{
    return norm() < number.norm();
}
bool myComplex::operator <=(const myComplex& number) const
{
    return norm() <= number.norm();
}
// Overloaded unary operators
myComplex& myComplex::operator ++(){ // 전위
    realPart++;
    return *this;
}
myComplex myComplex::operator ++(int){ // 후위
    myComplex temp(*this);
    ++* this;
    return temp;
}

myComplex& myComplex::operator--(){
    realPart--;
    return *this;
}
myComplex myComplex::operator --(int){
    myComplex temp(*this);
    --* this;
    return temp;
}
myComplex myComplex::operator -() // unary minus
{
    return myComplex(-realPart, -imaginaryPart);
}
myComplex myComplex::operator ~() // unary minus
{
    return myComplex(realPart, -imaginaryPart);
}

// private function
int myComplex::norm() const
{
    return realPart * realPart + imaginaryPart * imaginaryPart;
}
ostream &operator <<(ostream &outStream, const myComplex& number)
{
    outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return outStream;
}
istream &operator >>(istream &inStream, myComplex& number)
{
    inStream >> number.realPart >> number.imaginaryPart;
    return inStream;
}