/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #13.1 header file
 * Sun Nov 12 11:07:13 PST 2017
 * Goal: Define syntactically correct classes that use dynamic memory in
 * accordance with good programming practice. Explain the "Big-Three" member
 * functions that are required when a class uses dyamic memory.
 */

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>

namespace cs_mystring {
    class MyString {
        public:
            MyString(); // constructor
            // Precondition:
            // Postcondition:

            MyString(const char* inString); // constructor
            // Precondition:
            // Postcondition:

            MyString(const MyString& right); // copy constructor
            // Precondition:
            // Postcondition:

            ~MyString(); // destructor
            // Precondition:
            // Postcondition:

            int length() const;
            // Precondition:
            // Postcondition:

            friend std::ostream& operator<<(std::ostream& out, const MyString& right);
            // Precondition:
            // Postcondition:

            // friend std::istream& operator>>(std::istream& in, MyString& right);
            // Precondition:
            // Postcondition:

            friend bool operator<(const MyString& left,const MyString& right);
            // Precondition: MyStrings 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to MyStrings.
            // Postcondition: returns boolean 'true' if right is mathematically greater
            // than left. Returns boolean 'false' if left is mathematically greater than
            // right.

            friend bool operator>(const MyString& left,const MyString& right);
            // Precondition: MyStrings 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to MyStrings.
            // Precondition: MyStrings 'left' and 'right'. Integers will be coerced
            // to MyStrings.
            // Postcondition: returns boolean 'true' if 'left' is mathematically greater
            // than 'right'. Returns boolean 'false' if 'right' is mathematically greater than
            // 'left'.

            friend bool operator==(const MyString& left,const MyString& right);
            // Precondition: MyStrings 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to MyStrings.
            // Postcondition: returns boolean 'true' if 'left' and 'right' are
            // mathematically equal to each other. Returns boolean 'false' if
            // 'right' or 'left' are not mathematically equal.

            friend bool operator!=(const MyString& left,const MyString& right);
            // Precondition: MyStrings 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to MyStrings.
            // Postcondition: returns boolean 'true' if 'left' or 'right' are
            // mathematically uneaqual to each other. Returns boolean 'false'
            // if 'right' and 'left' are mathematically equal to each other.

            friend bool operator<=(const MyString& left,const MyString& right);
            // Precondition: MyStrings 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to MyStrings.
            // Postcondition: returns boolean 'true' if 'right' is mathematically
            // greater than or equal to 'left'. Returns boolean 'false' if
            // 'left' is mathematically greater than 'right'.

            friend bool operator>=(const MyString& left,const MyString& right);
            // Precondition: MyStrings 'left' and 'right' to be compared mathematically.
            // Integers will be coerced to MyStrings.
            // Postcondition: returns boolean 'true' if 'left' is mathematically greater
            // than or equal to 'right'. Returns boolean 'false' if 'right' is
            // mathematically greater than 'left'.

            MyString operator=(const MyString& right);
            // Precondition:
            // Postcondition:

            char operator[](int index) const;
            // Precondition:
            // Postcondition:

            char& operator[](int index);
            // Precondition:
            // Postcondition:

        private:
            char *pstring;

    };
}
#endif
/* sample run:
mdavis@jarvis:~/school/cis278/a13$ g++ mystring.cpp a13_1.cpp -o a13_1 && ./a13_1
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing apple to
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true
Comparing  to Banana
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing Banana to Banana
    Is left < right? false
    Is left <= right? true
    Is left > right? false
    Is left >= right? true
    Does left == right? true
    Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing why to wackity
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is Binky
val is winky
after assign,  val is Binky
mdavis@jarvis:~/school/cis278/a13$
*/
