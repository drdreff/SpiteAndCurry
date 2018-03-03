/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #11.1
 * Sun Oct 29 13:40:56 PDT 2017
 * Goal: Develop a class that performs all operations on fractions using
 * overloaded operators. This will be tested using a provided client main().
 * The test data is all very small, enabling a lack of integer overflow
 * protections.
 */
#include <iostream>
#include <cassert>

#include "Fraction.h"
using namespace std;

Fraction::Fraction(int in_numerator=0, int in_denominator=1) {
    assert(in_denominator != 0);
    numerator = in_numerator;
    denominator = in_denominator;
    this -> simplify();
}







ostream& operator<<(ostream& out, const Fraction& right){
    out << right.numerator << "/" << right.denominator;
    return out;
}






bool operator<(const Fraction& left,const Fraction& right){
    return ((right.denominator * left.numerator) < (left.denominator * right.numerator));
}






bool operator>(const Fraction& left,const Fraction& right){
    return ((right.denominator * left.numerator) > (left.denominator * right.numerator));
}






bool operator== (const Fraction& left,const Fraction& right){
    return (left.numerator * right.denominator == left.denominator * right.numerator);
}






bool operator!= (const Fraction& left,const Fraction& right){
    return (left.numerator * right.denominator != left.denominator * right.numerator);
}






bool operator<= (const Fraction& left,const Fraction& right){
    return (left.numerator * right.denominator <= left.denominator * right.numerator);
}






bool operator>= (const Fraction& left,const Fraction& right){
    return (left.numerator * right.denominator >= left.denominator * right.numerator);
}






Fraction operator+(const Fraction& left, const Fraction& right){
    Fraction result((left.numerator * right.denominator) +
        (right.numerator * left.denominator),
        (left.denominator * right.denominator));
    result.simplify();
    return result;
}






Fraction operator-(const Fraction& left, const Fraction& right){
    Fraction result((left.numerator * right.denominator) -
        (right.numerator * left.denominator),
        (left.denominator * right.denominator));
    result.simplify();
    return result;
}






Fraction operator*(const Fraction& left, const Fraction& right){
    Fraction result(left.numerator * right.numerator,
            left.denominator * right.denominator);
    result.simplify();
    return result;
}







Fraction operator/(const Fraction& left, const Fraction& right){
    Fraction result(left.numerator * right.denominator,
            left.denominator * right.numerator);
    result.simplify();
    return result;
}






Fraction Fraction::operator+=(const Fraction& right){
    *this = *this + right;
    return *this;
}






Fraction Fraction::operator-=(const Fraction& right){
    *this = *this - right;
    return *this;
}






Fraction Fraction::operator*=(const Fraction& right){
    *this = *this * right;
    return *this;
}






Fraction Fraction::operator/=(const Fraction& right){
    *this = *this / right;
    return *this;
}






Fraction Fraction::operator++(){
    *this +=1;
    return *this;
}






Fraction Fraction::operator++(int){
    Fraction temp(numerator,denominator);
    *this +=1;
    return temp;
}






Fraction Fraction::operator--(){
    *this -=1;
    return *this;
}






Fraction Fraction::operator--(int){
    Fraction temp(numerator,denominator);
    *this -=1;
    return temp;
}






void Fraction::simplify(){
    int mod = 2; // for finding the greatest common factor
    int gcf = 1; // to hold the greatest common factor

    while (mod <= numerator && mod <= denominator) {
        // stop looking for common factors once our modulus equals the lesser
        // of the nominator or denominator
        if ( numerator % mod == 0 && denominator % mod == 0 ){
            // once we have a clean divisor, store it for use later
            gcf = mod;
        }
        mod ++;
    }
    // update the object numerator and denominator with the GCF
    numerator /= gcf;
    denominator /= gcf;
}
