/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #12.1 -- header file
 * Sat Nov 4 14:24:35 PDT 2017
 * Goal: Develop a class that performs basic operations on fractions. This
 * will be tested using a provided client main(). The test data is all very
 * small, enabling a lack of integer overflow protections.
 */

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
namespace cs_Fraction {
    class Fraction {
        public:
            Fraction(int in_numerator=0, int in_denominator=1);
            // precondition: None. This constructor that builds the fraction object
            // an assigns 'in_numerator' to the nominator and 'in_denominator' to
            // the denominator integer.
            // postcondition: A Fraction object is created with nominator and
            // denominator of this Fraction object set to 'in_numerator' and
            // 'in_denominator' respectively.

            friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
            // Precondition: output stream 'out' and a Fraction 'right'.
            // Postcondition: otput strem recieves the Fraction 'right' in the
            // form 'X+Y/Z' where X is whole number formed from an improper
            // fraction, Y is the numerator and Z is the denominator.
            // X is signed.

            friend std::istream& operator>>(std::istream& in, Fraction& right);
            // Precondition: input stream 'in' and a Fraction object 'right'.
            // The stream must series of integers and characters in the form
            // X+Y/Z where X is an optional signed integer, Y and Z are integers to
            // represent a mathematical fraction in any form or a single integer.
            // Postcondition: the parameter fraction will be altered to contain
            // a reduced fraction. The function will continue to consume the
            // stream until a character other than other than integers, '+' or
            // '/' are encountered.

            friend bool operator<(const Fraction& left,const Fraction& right);
            // Precondition: Fractions 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to Fractions.
            // Postcondition: returns boolean 'true' if right is mathematically greater
            // than left. Returns boolean 'false' if left is mathematically greater than
            // right.

            friend bool operator>(const Fraction& left,const Fraction& right);
            // Precondition: Fractions 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to Fractions.
            // Precondition: Fractions 'left' and 'right'. Integers will be coerced
            // to Fractions.
            // Postcondition: returns boolean 'true' if 'left' is mathematically greater
            // than 'right'. Returns boolean 'false' if 'right' is mathematically greater than
            // 'left'.

            friend bool operator==(const Fraction& left,const Fraction& right);
            // Precondition: Fractions 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to Fractions.
            // Postcondition: returns boolean 'true' if 'left' and 'right' are
            // mathematically equal to each other. Returns boolean 'false' if
            // 'right' or 'left' are not mathematically equal.

            friend bool operator!=(const Fraction& left,const Fraction& right);
            // Precondition: Fractions 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to Fractions.
            // Postcondition: returns boolean 'true' if 'left' or 'right' are
            // mathematically uneaqual to each other. Returns boolean 'false'
            // if 'right' and 'left' are mathematically equal to each other.

            friend bool operator<=(const Fraction& left,const Fraction& right);
            // Precondition: Fractions 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to Fractions.
            // Postcondition: returns boolean 'true' if 'right' is mathematically
            // greater than or equal to 'left'. Returns boolean 'false' if
            // 'left' is mathematically greater than 'right'.

            friend bool operator>=(const Fraction& left,const Fraction& right);
            // Precondition: Fractions 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to Fractions.
            // Postcondition: returns boolean 'true' if 'left' is mathematically greater
            // than or equal to 'right'. Returns boolean 'false' if 'right' is
            // mathematically greater than 'left'.

            friend Fraction operator+(const Fraction& left, const Fraction& right);
            // Precondition: Fractions 'left' and 'right'. Integers will be coerced
            // to Fractions.
            // Postcondition: returns a Fraction containing the mathematical sum
            // of 'left' added to 'right'.

            friend Fraction operator-(const Fraction& left, const Fraction& right);
            // Precondition: Fractions 'left' and 'right'. Integers will be coerced
            // to Fractions.
            // Postcondition: retuns a Fraction containing the mathematical
            // difference of 'left' subtracted from 'right'

            friend Fraction operator*(const Fraction& left, const Fraction& right);
            // Precondition: Fractions 'left' and 'right'. Integers will be coerced
            // to Fractions.
            // Postcondition: returns a Fraction containing the product of 'left'
            // multiplied by 'right'

            friend Fraction operator/(const Fraction& left, const Fraction& right);
            // Precondition: Fractions 'left' and 'right'. Integers will be coerced
            // to Fractions.
            // Postcondition: returns a Fraction containing the quotient of 'left'
            // divided by 'right'

            Fraction operator+=(const Fraction& right);
            // Precondition: this Fraction object and Fraction 'right'. An
            // integer passed as 'right' will be coerced to a Fraction.
            // Postcondition: this Fraction is assigned the value of this Fraction
            // and 'right' added together.

            Fraction operator-=(const Fraction& right);
            // Precondition: this Fraction object and Fraction 'right'. An
            // integer passed as 'right' will be coerced to a Fraction.
            // Postcondition: this Fraction is assigned the difference between
            // itself and 'right'.

            Fraction operator*=(const Fraction& right);
            // Precondition: this Fraction object and Fraction 'right'. An
            // integer passed as 'right' will be coerced to a Fraction.
            // Postcondition: this Fraction is assigned the product of itself
            // multiplied by 'right'

            Fraction operator/=(const Fraction& right);
            // Precondition: this Fraction object and Fraction 'right'. An
            // integer passed as 'right' will be coerced to a Fraction.
            // Postcondition: this Fraction is assigned the value of itself
            // divided by 'right'

            Fraction operator++();
            // Precondition: this Fraction must be properly decalred.
            // Postcondition: this fraction is preincremented by the integer value of 1
            // before returning.

            Fraction operator++(int);
            // Precondition: this Fraction must be properly decalred.
            // Postcondition: this Fraction is postincremented by the integer value of 1
            // before returning. Returns the value of the fraction before incrementing.

            Fraction operator--();
            // Precondition: this Fraction must be properly decalred.
            // Postcondition: this Fraction is pre-decremented by the integer
            // value of 1 before returning.

            Fraction operator--(int);
            // Precondition: this Fraction must be properly decalred.
            // Postcondition: this Fraction is post-decremented by the integer
            // value of 1 before returning. Returns the value of the fraction
            // before incrementing.

        private:
            int numerator; // integer to hold the numerator of the fraction
            int denominator; // integer to hold the denominator of the fraction

            void simplify();
            // precondition: this Fraction must be a valid Fraction.
            // postcondition: The nominator and denominator of this Fraction object
            // are fully reduced to the lowest improper terms.
    };
} // close the namespace

#endif
/* Sample run:
mdavis@jarvis:~/school/cis278/a12$ g++ fracttest.cpp fraction.cpp -o fracttest && ./fracttest
----- Testing basic Fraction creation & printing
(Fractions should be in reduced form, and as mixed numbers.)
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

----- Now reading Fractions from file
Read Fraction = 1/3
Read Fraction = 1/2
Read Fraction = 3/4
Read Fraction = -4/5
Read Fraction = 6
Read Fraction = 5
Read Fraction = -8
Read Fraction = 1+2/5
Read Fraction = -16+2/3
Read Fraction = 1+1/4
Read Fraction = 2
Read Fraction = -4+1/4
Read Fraction = -10+5/6

----- Testing relational operators between Fractions
Comparing 1/2 to 1/2
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false
Comparing 1/2 to -1/2
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing -1/2 to 1/10
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing 1/10 to 0
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing 0 to 0
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -1/2 to 2
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing -3 to 1/4
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true

----- Testing binary arithmetic between Fractions
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between Fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on Fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3
mdavis@jarvis:~/school/cis278/a12$
*/
