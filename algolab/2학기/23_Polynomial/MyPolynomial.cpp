#include "MyPolynomial.h"

// output operator
ostream& operator <<(ostream& outStream, const myPolynomial& poly) {
    bool is_zero = true;
    if (poly == myPolynomial::ZERO) return outStream << 0;

    outStream << poly.po[0];
    if (poly.po[0].getCoeff() != 0) is_zero = false;

    for (int i = 1; i < poly.no_term; i++) {
        if (poly.po[i].getCoeff() != 0)
            is_zero = false;

        if (poly.po[i].getCoeff() > 0)
            outStream << '+';

        outStream << poly.po[i];
    }
    if (is_zero) return outStream << '0';

    return outStream;
}

const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x

myPolynomial::myPolynomial(int c, unsigned e) :no_term(1) {
    po[0].coeff = c, po[0].exp = e;
}

myPolynomial::myPolynomial(int nTerms, int mono[]) : no_term(nTerms) {
    for (int i = 0; i < no_term; i++)
        po[i].coeff = mono[2 * i], po[i].exp = mono[2 * i + 1];

    sort(po, po + no_term);
    degree = po[0].exp;
    if (nTerms == 1 && po[0].coeff == 0 && po[0].exp == 0) degree = 0;
}

// copy constructor
myPolynomial::myPolynomial(const myPolynomial& poly) :no_term(poly.no_term), degree(poly.degree) {
    for (int i = 0; i < no_term; i++)
        po[i].coeff = poly.po[i].coeff, po[i].exp = poly.po[i].exp;
}

// overloaded operators
bool myPolynomial::operator == (const myPolynomial& poly) const {
    if (no_term != poly.no_term) return false;

    for (int i = 0; i < no_term; i++)
        if (po[i].coeff != poly.po[i].coeff || po[i].exp != poly.po[i].exp) return false;

    return true;
}

bool myPolynomial::operator != (const myPolynomial& poly) const {
    return !(*this == poly);
}

myPolynomial& myPolynomial::operator += (const myPolynomial& poly) {
    return *this = *this + poly;
}

myPolynomial& myPolynomial::operator -= (const myPolynomial& poly) {
    return *this = *this - poly;
}

myPolynomial& myPolynomial::operator *= (const myPolynomial& poly) {
    return *this = *this * poly;
}

myPolynomial& myPolynomial::operator *= (int k) {
    return *this = *this * myPolynomial(k, (unsigned)0);
}

myPolynomial myPolynomial::operator -() const {
    myPolynomial ans(*this);
    for (int i = 0; i < no_term; i++)
        ans.po[i].coeff *= -1;

    return ans;
}

myPolynomial myPolynomial::operator *(int k) const {
    return *this * myPolynomial(k, (unsigned)0);
}

myPolynomial myPolynomial::operator +(const myPolynomial& poly) const {
    int arr[102] = { 0, };
    int apos = 0, bpos = 0, size = 0;

    for (size; apos != no_term && bpos != poly.no_term; size++) {
        if (po[apos].exp > poly.po[bpos].exp)
            arr[2 * size] = po[apos].coeff, arr[2 * size + 1] = po[apos].exp, apos++;
        else if (po[apos].exp < poly.po[bpos].exp)
            arr[2 * size] = poly.po[bpos].coeff, arr[2 * size + 1] = poly.po[bpos].exp, bpos++;
        else
            arr[2 * size] = po[apos].coeff + poly.po[bpos].coeff, arr[2 * size + 1] = po[apos].exp, apos++, bpos++;
    }

    while (apos != no_term)
        arr[2 * size] = po[apos].coeff, arr[2 * size + 1] = po[apos].exp, apos++, size++;

    while (bpos != poly.no_term)
        arr[2 * size] = poly.po[bpos].coeff, arr[2 * size + 1] = poly.po[bpos].exp, bpos++, size++;

    return myPolynomial(size, arr);
}

myPolynomial myPolynomial::operator -(const myPolynomial& poly) const {
    return *this + (-poly);
}

myPolynomial myPolynomial::operator *(const myPolynomial& poly) const {
    myPolynomial ans(0, (unsigned)0);

    for (int i = 0; i < no_term; i++) {
        myPolynomial temp(poly);
        for (int j = 0; j < poly.no_term; j++) {
            temp.po[j].coeff *= po[i].coeff;
            temp.po[j].exp += po[i].exp;
        }
        ans += temp;
    }

    return ans;
}

long myPolynomial::operator() (int x) const {
    long ans = 0;
    for (int i = 0; i < no_term; i++)
        ans += po[i].coeff * (long)pow(x, po[i].exp);

    return ans;
} 

int myPolynomial::getDegree() const {
    return degree;
}

unsigned myPolynomial::getNumTerms() const {
    return no_term;
} 

myPolynomial myPolynomial::ddx() const {
    myPolynomial ans(*this);
    for (int i = 0; i < no_term; i++)\
        ans.po[i] = po[i].ddx();

    return ans;
} 

myPolynomial operator *(int k, const myPolynomial& poly) {
    return myPolynomial(k, (unsigned)0) * poly;
}
