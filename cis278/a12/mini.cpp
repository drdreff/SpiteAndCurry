/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #10.1
 * Sat Oct 21 16:33:44 PDT 2017
 * Goal:cut and paste the client program below.
 */
 #include <iostream>
 #include "Fraction.h"
 #include <fstream>
 #include <cassert>
 #include <string>

using namespace std;
using namespace cs_Fraction;
bool eof(ifstream& in);
string boolString(bool convertMe);

int main()
{
    Fraction f1(-5,-2);
    Fraction f2(1,-4);

    int i1 =1;
    int i2 =2;
    Fraction result;

    cout << "5/2: " << f1 << endl;
    cout << "-1/4: " << f2 << endl;

    f1 -= 10;

    cout << "5/2 -10 = -7+1/2: " <<  f1 << endl;

    cout << "\n----- Testing basic Fraction creation & printing\n";
    cout << "(Fractions should be in reduced form, and as mixed numbers.)\n";

    const Fraction fr[] = {Fraction(4, 8), Fraction(-15,21),
                           Fraction(10), Fraction(12, -3),
                           Fraction(), Fraction(28, 6), Fraction(0, 12)};

    for (int i = 0; i < 7; i++){
        cout << "Fraction [" << i <<"] = " << fr[i] << endl;
    }


    cout << "\n----- Now reading Fractions from file\n";
    ifstream in("Fraction.txt");
    assert(in);
    while (!eof(in)) {
        Fraction f;
        if (in.peek() == '#') {
            in.ignore(128, '\n');                       //skip this line, it's a comment
        } else {
            in >> f;
            cout << "Read Fraction = " << f << endl;
        }
    }

    /*
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
    */
}
