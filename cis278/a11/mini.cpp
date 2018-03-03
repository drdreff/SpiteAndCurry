/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #10.1
 * Sat Oct 21 16:33:44 PDT 2017
 * Goal:cut and paste the client program below.
 */
#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
    Fraction f1(1,2);
    Fraction f2(1,4);
    int i1 =1;
    int i2 =2;
    Fraction result;

    cout << "The result starts off at " << result << endl;
    result = f1 + f2;
    cout << "The sum of "<< f1 << " and " << f2 << " is " << result << endl;
    result = f1 - f2;
    cout << "The difference of "<< f1 << " and " << f2 << " is " << result << endl;
    result = f1 * f2;
    cout << "The product of "<< f1 << " and " << f2 << " is " << result << endl;
    result = f1 / f2;
    cout << "The quotient of "<< f1 << " and " << f2 << " is " << result << endl;

    result += f1;
    cout << "adding " << f1 << " is " << result << endl;
    result -= f1;
    cout << "subtracting " << f1 << " is " << result << endl;
    result *= f1;
    cout << "multiplying " << f1 << " is " << result << endl;
    result /= f1;
    cout << "dividing " << f1 << " is " << result << endl;

    cout << "comparing "<< f1 << " < " << f2 << (f1 < f2) << endl;
    cout << "comparing "<< f2 << " < " << f1 << (f2 < f1) << endl;

    cout << "comparing "<< f1 << " > " << f2 << (f1 > f2) << endl;
    cout << "comparing "<< f2 << " > " << f1 << (f2 > f1) << endl;
    cout << "comparing "<< f1 << " < " << i1 << (f1 < i1) << endl;
    cout << "comparing "<< f1 << " > " << i1 << (f1 > i1) << endl;

    cout << "comparing "<< f1 << " == 1/2 " << ((f2 *2) == f1) << endl;
    cout << "comparing "<< f2 << " == " << (f1 *2)<< ((f1 *2) == f2) << endl;
    cout << "comparing "<< f1 << " != 1/2 " << ((f2 *2) != f1) << endl;
    cout << "comparing "<< f2 << " != " << (f1 *2)<< ((f1 *2) != f2) << endl;
    cout << "preincrement " << f1 ;
    cout << " " << (++f1) << endl;
    cout << "postincrement " << f1 ;
    cout << " " << (f1++);
    cout << f1 << endl;
/*
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

    const Fraction f3(12, 8);
    const Fraction f4(202, 303);
    result = f3.multipliedBy(f4);
    cout << "The product of ";
    f3.print();
    cout << " and ";
    f4.print();
    cout << " is ";
    result.print();
    cout << endl;
*/
}
