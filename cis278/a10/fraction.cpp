/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #10.1
 * Sat Oct 21 16:33:44 PDT 2017
 * Goal: Develop a class that performs basic operations on fractions. This
 * will be tested using a provided client main(). The test data is all very
 * small, enabling a lack of integer overflow protections.
 */
 #include <iostream>
 #include "Fraction.h"
 using namespace std;

Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}






Fraction::Fraction(int in_numerator, int in_denominator) {
    numerator = in_numerator;
    denominator = in_denominator;
    this -> simplify();
}







Fraction Fraction::addedTo(Fraction f_in) const{
    Fraction result((numerator * f_in.denominator) + (f_in.numerator * denominator),
        (denominator * f_in.denominator));
    result.simplify();
    return result;
}






Fraction Fraction::subtract(Fraction f_in) const{
    Fraction result((numerator * f_in.denominator) - (f_in.numerator * denominator),
        (denominator * f_in.denominator));
    result.simplify();
    return result;
}






Fraction Fraction::multipliedBy(Fraction f_in) const{
    Fraction result(numerator * f_in.numerator, denominator * f_in.denominator);
    result.simplify();
    return result;
}







Fraction Fraction::dividedBy(Fraction f_in) const{
    Fraction result(numerator * f_in.denominator, denominator * f_in.numerator);
    result.simplify();
    return result;
}






bool Fraction::isEqualTo(Fraction f_in) const{
    return (numerator * f_in.denominator == denominator * f_in.numerator);
}






void Fraction::print() const{
    cout << numerator << "/" << denominator ;
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
