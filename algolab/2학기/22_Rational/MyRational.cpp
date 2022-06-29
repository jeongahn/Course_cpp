#include "MyRational.h"

myRational::myRational(long num, long den)
{
    this -> _num = num;
    this -> _den = den;
}
myRational::myRational(const myRational &rat){
    this -> _num = rat._num;
    this -> _den = rat._den;
}
long myRational::getNumerator() const{
    return _num;
}
long myRational::getDenominator() const{
    return _den;
}
myRational myRational::reciprocal() const{
    return myRational(_den, _num);
}
//operator
myRational myRational::operator +(const myRational &rat) const
{   
    myRational r;
    r._num = _num * rat._den + rat._num * _den;
    r._den = _den * rat._den;
    r.reduce();
    return r;
}
myRational myRational::operator +(long value) const
{
    myRational r;
    myRational tmp(value);
    r = *this + tmp;
    r.reduce();

    return r;
}
myRational operator +(long value, const myRational &rat){
    return rat + value;
}
myRational myRational::operator -(const myRational &rat) const
{
    myRational r;
    r._num = _num * rat._den - rat._num * _den;
    r._den = _den * rat._den;
    r.reduce();
    return r;
}
myRational myRational::operator -(long value) const{
    myRational r;
    myRational tmp(value);
    r = *this - tmp;
    r.reduce();
    return r;
}
myRational operator-(long value, const myRational &rat){
    return -(rat - value);
}
myRational myRational::operator *(const myRational &rat) const
{
    myRational r;
    r._num = _num * rat._num;
    r._den = _den * rat._den;
    r.reduce();
    return r;
}
myRational myRational::operator *(long value) const{
    myRational r;
    myRational tmp(value);
    r = *this * tmp;
    r.reduce();
    return r;
}
myRational operator *(long value, const myRational &rat){
    return rat * value;
}
myRational myRational::operator /(const myRational &rat) const
{
    myRational r;
    if(rat._num == 0){
        return 0;
    }else{
        r._num = _num * rat._den;
        r._den = _den * rat._num;
    }
    return r;  
}
myRational myRational::operator /(long value) const{
    myRational r;
    myRational tmp(value);
    if(value == 0){
        return 0;
    }else{
        r = *this / tmp;
        r.reduce();
        return r;
    }
}
myRational operator /(long value, const myRational &rat){
    myRational tmp(value);
    if(rat._num == 0){
        return 0;
    }else{
        return tmp / rat;
    }
}
//assignment operators
myRational& myRational::operator =(const myRational &rat){
    _num = rat._num;
    _den = rat._den;

    return *this;
}
myRational& myRational::operator +=(const myRational &rat){
    _num = ((_num * rat._den) + (_den * rat._num));
    _den *= rat._den;
    this->reduce();
    return *this;
}   
myRational& myRational::operator -=(const myRational &rat){
    _num = ((_num * rat._den) - (_den * rat._num));
    _den *= rat._den;
    this->reduce();
    return *this;
}
myRational& myRational::operator *=(const myRational &rat){
    _num *= rat._num;
    _den *= rat._den;
    this->reduce();
    return *this;
}
myRational& myRational::operator /=(const myRational &rat){
    if(rat._num == 0){
        *this = 0;
    }
    _num *= rat._den;
    _den *= rat._num;
    this->reduce();
    return *this;
}
//comparison operators 
bool myRational::operator== (const myRational &rat) const
{
    bool result;
    myRational r(rat);
    r.reduce();
    if((this->_num == r._num) && (this->_den == r._den)){
        result = true;
    }else{
        result = false;
    }
    return result;
}
bool myRational::operator== (long value) const
{
    bool result;
    myRational r(value);
    r.reduce();
    result = (*this == r);
    return result;
}
bool operator== (long value, const myRational &rat)
{
    bool result;
    result = (rat == value);
    return result;
}
bool myRational::operator!= (const myRational &rat) const
{
    return !(*this == rat);
}
bool myRational::operator!= (long value) const{
    return !(*this == value);
}
bool operator!= (long value, const myRational &rat){
    return !(value == rat);
}
bool myRational::operator> (const myRational &rat) const{
    bool result;
    myRational r(rat);
    r.reduce();
    if ((this->_num / this->_den) > (r._num / r._den)){
        result = true;
    }else{
        result = false;
    }
    return result;
}
bool myRational::operator> (long value) const{
    bool result;
    myRational r(value);
    result = (*this > r);
    return result;
}
bool operator> (long value, const myRational &rat){
    bool result;
    myRational r(rat);
    r.reduce();
    result = (r < value);
    return result;
}
bool myRational::operator< (const myRational &rat) const{
    bool result;
    myRational r(*this);
    r.reduce();
    if(!(r > rat) && !(r == rat)){
        result = true;
    }else{
        result = false;
    }
    return result;
}
bool myRational::operator< (long value) const{
    bool result;
    myRational r(value);
    result = (*this < r);
    return result;
}
bool operator< (long value, const myRational &rat){
    bool result;
    result = (rat > value);
    return result;
}
bool myRational::operator>= (const myRational &rat) const{
    bool result;
    myRational r(rat);
    r.reduce();
    if(!(*this < r)){
        result = true;
    }else{
        result = false;
    }
    return result;
}
bool myRational::operator>= (long value) const{
    bool result;
    myRational r(value);
    result = (*this >= r);
    return result;
}
bool operator>= (long value, const myRational &rat){
    bool result;
    result = (rat <= value);
    return result;
}
bool myRational::operator<= (const myRational &rat) const{
    bool result;
    myRational r(rat);
    r.reduce();
    if(!(*this > r)){
        result = true;
    }else{
        result = false;
    }
    return result;
}
bool myRational::operator<= (long value) const{
    bool result;
    myRational r(value);
    result = (*this <= r);
    return result;
}
bool operator<= (long value, const myRational &rat){
    bool result;
    result = (rat >= value);
    return result;
}
// Overloaded unary operators
myRational& myRational::operator ++(){ //전위
    _num += _den;
    this->reduce();
    return *this;
}
myRational myRational::operator ++(int){ //후위
    myRational r(*this);
    _num += _den;
    this->reduce();
    return r;
}
myRational& myRational::operator --(){ //전위
    _num -= _den;
    this->reduce();
    return *this;
}
myRational myRational::operator --(int){ //후위
    myRational r(*this);
    _num -= _den;
    return r;
}
myRational myRational::operator -() const{
    myRational r(-(this->_num), (this->_den));
    return r;
}

ostream &operator <<(ostream &outStream, const myRational& r)
{   
    myRational tmp(r);
    tmp.reduce();
    if (tmp._num == 0)
        outStream << 0;
    else if (tmp._den == 1)
        outStream << tmp._num;
    else
        outStream << tmp._num << "/" << tmp._den;
    return outStream;
}
istream &operator >>(istream &inStream, myRational& r)
{
    inStream >> r._num >> r._den;
    
    if (r._den == 0)
    {
        r._num = 0; 
        r._den = 1;
    }
    r.reduce();
    return inStream;
}
long myRational::gcd(long m, long n)
{
    if (m == n)
        return n;
    else if (m < n)
        return gcd(m, n-m);
    else
        return gcd(m-n, n);
}
void myRational::reduce()
{   
    if (_num == 0 || _den == 0)
    {
        _num = 0;
        _den = 1;
        return;
    }

    if (_den < 0)
    {
        _den *= -1;
        _num *= -1;
    }
    if (_num == 1)
    return;
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
} 