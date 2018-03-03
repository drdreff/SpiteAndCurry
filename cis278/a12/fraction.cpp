/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #11.1
 * Sat Nov 4 14:24:35 PDT 2017
 * Goal: Develop a class that performs all operations on fractions using
 * overloaded operators. This will be tested using a provided client main().
 * The test data is all very small, enabling a lack of integer overflow
 * protections.
 */
#include <iostream>
#include <cassert>

#include "Fraction.h"
using namespace std;

namespace cs_Fraction {

    Fraction::Fraction(int in_numerator, int in_denominator) {
        assert(in_denominator != 0);
        numerator = in_numerator;
        denominator = in_denominator;
        this -> simplify();
    }







    ostream& operator<<(ostream& out, const Fraction& right){

        int wholeNumber = right.numerator / right.denominator;

        if (wholeNumber != 0){
            out << wholeNumber;
            Fraction temp = right;
            if (wholeNumber < 0 ){
                temp *= -1;
                temp += wholeNumber;
            } else {
                temp = right - wholeNumber;
            }
            if (temp.numerator != 0 ){
                out << '+' << temp.numerator << '/' << temp.denominator;
            }
        } else {
            if (right.numerator != 0){
                out << right.numerator << '/' << right.denominator;
            } else {
                out << 0;
            }
        }
        return out;
    }






    istream& operator>>(istream& in, Fraction& right){
        int temp =0 ;
        int wholeNumber = 0;
        bool reading = true;

        while (reading){
            in >> temp;
            if (in.peek() == '+'){
                // reading a whole number integer, preserve the sign
                wholeNumber = temp;
                in.ignore();
            } else if (in.peek() == '/'){
                // reading a numerator
                right.numerator = temp;
                in.ignore();
            } else {
                // reading a denominator or a whole number.
                reading = false;
                if (right.numerator == 0 ){ // naked whole number
                    right.numerator = temp;
                } else {
                    //cout << right << endl;
                    right.denominator = temp;
                    wholeNumber *= right.denominator;
                    if (wholeNumber < 0 ){
                        right.numerator = wholeNumber - right.numerator;
                    } else {
                        right.numerator += wholeNumber;
                    }
                } // done processing denominator
            } // done reading
        } // end while
        right.simplify();
        return in;
    } // end operator>>






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
        int sign = 1; // to store sign

        // clean up stray negative denominator
        if (denominator < 0 ){
            numerator *= -1;
            denominator *= -1;
        }

        // turn 0/x into 0/1
        if (numerator == 0 ){
            denominator = 1;
        }
        if (numerator < 0 ){ // store the sign, operate on positive numbers only
            numerator *= -1;
            sign = -1;
        }
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
        numerator *= sign; // reset sign
    } // end simplify
}
