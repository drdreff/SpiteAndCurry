/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #9.1
 * Sun Oct 15 16:59:36 PDT 2017
 * Goal: Develop a class that performs basic operations on fractions. This
 * will be tested using a provided client main(). The test data is all very
 * small, enabling a lack of integer overflow protections.
 */
 #include <iostream>
 using namespace std;


class Fraction {
    public:
        void set(int numerator, int denominator);
        // precondition: a fraction has been declared. Since there are no
        // constructors, this function will set the values of the two class
        // variables.
        // postcondition: this object's numerator is set to in_num and the
        // denominator is set to in_denom. No error checking for zero values
        // is written in here.

        Fraction addedTo(Fraction f_in);
        // precondition: f_in is a Fraction with a non-zero denominator.
        // additionally a Fraction object must exist for this function
        // to return a value to.
        // postcondition: A Fraction object is returned that contains
        // the sum of this object's values and f_in's values. The
        // fraction is not simplified.

        Fraction subtract(Fraction f_in);
        // precondition: f_in is a Fraction with a non-zero denominator.
        // additionally a Fraction object must exist for this function
        // to return a value to.
        // postcondition: A Fraction object is returned that contains
        // the difference of this object's values and f_in's values. The
        // fraction is not simplified.

        Fraction multipliedBy(Fraction f_in);
        // precondition: f_in is a Fraction with a non-zero denominator.
        // additionally a Fraction object must exist for this function
        // to return a value to.
        // postcondition: A Fraction object is returned that contains
        // the sum of this object's values and f_in's values. The
        // fraction is not simplified.

        Fraction dividedBy(Fraction f_in);
        // precondition: f_in is a Fraction with a non-zero denominator.
        // additionally a Fraction object must exist for this function
        // to return a value to.
        // postcondition: A Fraction object is returned that contains
        // the sum of this object's values and f_in's values. The
        // fraction is not simplified.

        bool isEqualTo(Fraction f_in);
        // precondition: f_in is a Fraction with a non-zero denominator.
        // postcondition: A boolean condition is returned. It returns 'true'
        // if the two fractions are equal to each other.

        void print();
        // precondition: f_in is a Fraction with a non-zero denominator.
        // postcondition: The nominator and denominator of Fraction object
        // are printed to stdout sepataed by the '/'

    private:
        int numerator; // integer to hold the numerator of the fraction
        int denominator; // integer to hold the denominator of the fraction
};






void Fraction::set(int in_num, int in_denom) {
    // some error checking should be here to prevent 0 value denominators
    numerator = in_num;
    denominator = in_denom;
}






Fraction Fraction::addedTo(Fraction f_in){
    Fraction result;
    result.set((numerator * f_in.denominator) + (f_in.numerator * denominator),
        (denominator * f_in.denominator));
    return result;
}






Fraction Fraction::subtract(Fraction f_in){
    Fraction result;
    result.set((numerator * f_in.denominator) - (f_in.numerator * denominator),
        (denominator * f_in.denominator));
    return result;
}






Fraction Fraction::multipliedBy(Fraction f_in){
    Fraction result;
    result.set(numerator * f_in.numerator, denominator * f_in.denominator);
    return result;
}







Fraction Fraction::dividedBy(Fraction f_in){
    Fraction result;
    result.set(numerator * f_in.denominator, denominator * f_in.numerator);
    return result;
}






bool Fraction::isEqualTo(Fraction f_in){
    return (numerator * f_in.denominator == denominator * f_in.numerator);
}






void Fraction::print(){
    cout << numerator << "/" << denominator ;
}






// main provided below.
#include <iostream>
using namespace std;

int main()
{
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
}

/* Commented run:
mdavis@jarvis:~/school/cis278$ ./a9_1
The product of 9/8 and 2/3 is 18/24
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two Fractions are not equal.
mdavis@jarvis:~/school/cis278$
*/
