/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #10.1 -- header file
 * Sat Oct 21 16:33:44 PDT 2017
 * Goal: Develop a class that performs basic operations on fractions. This
 * will be tested using a provided client main(). The test data is all very
 * small, enabling a lack of integer overflow protections.
 */

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
    public:
        Fraction();
        // precondition: None. This is the default constructor that builds the
        // fraction object an assigns '0' to the nominator and '1' to the
        // denominator integers.
        // postcondition: A Fraction object is created with nominator and
        // denominator of this Fraction object set to '0' and '1' respectively.

        Fraction(int in_numerator);

        Fraction(int in_numerator, int in_denominator);
        // precondition: None. This constructor that builds the fraction object
        // an assigns 'in_numerator' to the nominator and 'in_denominator' to
        // the denominator integer.
        // postcondition: A Fraction object is created with nominator and
        // denominator of this Fraction object set to 'in_numerator' and
        // 'in_denominator' respectively.

        friend std::ostream& operator<<(std::ostream& out, const Fraction& right);

        friend bool operator<(const Fraction& left,const Fraction& right);
        friend bool operator>(const Fraction& left,const Fraction& right);

        friend bool operator==(const Fraction& left,const Fraction& right);
        friend bool operator!=(const Fraction& left,const Fraction& right);
        friend bool operator<=(const Fraction& left,const Fraction& right);
        friend bool operator>=(const Fraction& left,const Fraction& right);

        friend Fraction operator+(const Fraction& left, const Fraction& right);
        friend Fraction operator-(const Fraction& left, const Fraction& right);
        friend Fraction operator*(const Fraction& left, const Fraction& right);
        friend Fraction operator/(const Fraction& left, const Fraction& right);

        Fraction operator+=(const Fraction& right);
        Fraction operator-=(const Fraction& right);
        Fraction operator*=(const Fraction& right);
        Fraction operator/=(const Fraction& right);

        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);

    private:
        int numerator; // integer to hold the numerator of the fraction
        int denominator; // integer to hold the denominator of the fraction

        void simplify();
        // precondition: this Fraction must be a valid Fraction.
        // postcondition: The nominator and denominator of this Fraction object
        // are fully reduced.
};

#endif
/* Sample run:
mdavis@jarvis:~/school/cis278$ g++ a10_1.cpp fraction.cpp -o a10_1 && ./a10_1
The result starts off at 0/1
The product of 9/8 and 2/3 is 3/4
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two Fractions are not equal.
The product of 3/2 and 2/3 is 1/1
mdavis@jarvis:~/school/cis278$
*/
