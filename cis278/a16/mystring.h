/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #13.1 header file
 * Sun Nov 12 11:07:13 PST 2017
 * Goal: Define syntactically correct classes that use dynamic memory in
 * accordance with good programming practice. Explain the "Big-Three" member
 * functions that are required when a class uses dyamic memory.

MyString(); // constructor
    Precondition: None
    Postcondition: a MyString class is created with an empty
    cstring.

MyString(const char* inString); // constructor
    Precondition: None
    Postcondition: A MyStringis constructed containing the characters
    of inString in the private cstring pstring.

MyString(const MyString& right); // copy constructor
    Precondition: a Mystring 'right' to be copied to a new MyString.
    Postcondition: A new MyString is created containing a copy of the
    'pstring' from 'right'.

~MyString(); // destructor
    Precondition: an instance of MyString to be destroyed.
    Postcondition: Memory previously allocated to the MyString
    is released to the operating system.

int length() const;
    Precondition: a vali MyString created.
    Postcondition: returns an integer equal to the number of characters
    stored in the MyString 'pstring'

friend std::ostream& operator<<(std::ostream& out, const MyString& right);
    Precondition: an output stream 'out' to feed the contents of MyString
    'pstring' to.
    Postcondition: Returns the output stream to the caller with the
    contents of 'right' concatenated onto it.

friend std::istream& operator>>(std::istream& in, MyString& right);
    Precondition: input stream 'in' and a MyString 'right'.
    Postcondition: the contyents of the input stream are consumed into
    the 'pstring' of 'right'. Thhe input stream is returned to the
    caller with the contents that wer copied removed from the stream.

friend bool operator<(const MyString& left,const MyString& right);
    Precondition: MyStrings 'left' and 'right' to be compared lexically.
    Cstrings will be coerced to MyStrings.
    Postcondition: returns boolean 'true' if right is lexically greater
    than left. Returns boolean 'false' if left is lexically greater than
    right.

friend bool operator>(const MyString& left,const MyString& right);
    Precondition: MyStrings 'left' and 'right' to be compared lexically.
    Cstrings will be coerced to MyStrings.
    Precondition: MyStrings 'left' and 'right'. Cstrings will be coerced
    to MyStrings.
    Postcondition: returns boolean 'true' if 'left' is lexically greater
    than 'right'. Returns boolean 'false' if 'right' is lexically greater than
    'left'.

friend bool operator==(const MyString& left,const MyString& right);
    Precondition: MyStrings 'left' and 'right' to be compared lexically.
    Cstrings will be coerced to MyStrings.
    Postcondition: returns boolean 'true' if 'left' and 'right' are
    lexically equal to each other. Returns boolean 'false' if
    'right' or 'left' are not lexically equal.

friend bool operator!=(const MyString& left,const MyString& right);
    Precondition: MyStrings 'left' and 'right' to be compared lexically.
    Cstrings will be coerced to MyStrings.
    Postcondition: returns boolean 'true' if 'left' or 'right' are
    lexically uneaqual to each other. Returns boolean 'false'
    if 'right' and 'left' are lexically equal to each other.

friend bool operator<=(const MyString& left,const MyString& right);
    Precondition: MyStrings 'left' and 'right' to be compared lexically.
    Cstrings will be coerced to MyStrings.
    Postcondition: returns boolean 'true' if 'right' is lexically
    greater than or equal to 'left'. Returns boolean 'false' if
    'left' is lexically greater than 'right'.

friend bool operator>=(const MyString& left,const MyString& right);
    Precondition: MyStrings 'left' and 'right' to be compared lexically.
    Cstrings will be coerced to MyStrings.
    Postcondition: returns boolean 'true' if 'left' is lexically greater
    than or equal to 'right'. Returns boolean 'false' if 'right' is
    lexically greater than 'left'.

MyString operator=(const MyString& right);
    Precondition: a target MyString to be assigned the contents of
    'right'.
    Postcondition: The contents of 'right' are deeply copied into the
    target MyString.

char operator[](int index) const;
    Precondition: a MyString properly declared and an integer to
    reference a character at the 'index' location in the MyString.
    Postcondition: returns a copy of the character contained in the
    MyString at offset of the 'index'. Throws errors for attempting
    to refer to a character outside the range of MyString's 'pstring'

char& operator[](int index);
    Precondition: a MyString properly declared and an integer to
    reference a character at the 'index' location in the MyString.
    Postcondition: returns a reference to to a char at the offset
    indicated by 'index' to allow for the assignment of a new value
    to the specific character at the offset of 'index'

friend MyString operator+(const MyString& left, const MyString& right);
    Precondition: two MyStrings 'left' and 'right'.
    Postcondition: returns a MyStringwith the contents of 'left' and
    'right' concatenated together.

MyString operator+=(const MyString& right);
    Precondition: a MyString target and MyString 'right'.
    Postcondition: the target MyString is returned with the contents
    of 'right' concatenated on the end.

void read(std::istream& in, const char delim );
    Precondition: an input stream 'in' to be read into this MyString
    Postcondition: The contents of the input stream are cusumed up to
    the vaue of 'delim'. The delimiter 'delim' is consumed but not
    returned.

 */

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>

namespace cs_mystring {
    class MyString {
        public:
            MyString(); // constructor
            MyString(const char* inString); // constructor
            MyString(const MyString& right); // copy constructor
            ~MyString(); // destructor
            int length() const;
            friend std::ostream& operator<<(std::ostream& out, const MyString& right);
            friend std::istream& operator>>(std::istream& in, MyString& right);
            friend bool operator<(const MyString& left,const MyString& right);
            friend bool operator>(const MyString& left,const MyString& right);
            friend bool operator==(const MyString& left,const MyString& right);
            friend bool operator!=(const MyString& left,const MyString& right);
            friend bool operator<=(const MyString& left,const MyString& right);
            friend bool operator>=(const MyString& left,const MyString& right);
            MyString operator=(const MyString& right);
            char operator[](int index) const;
            char& operator[](int index);
            friend MyString operator+(const MyString& left, const MyString& right);
            MyString operator+=(const MyString& right);
            void read(std::istream& in, const char delim );
        private:
            char *pstring;
            // static const int BUFFER_SIZE = 127;
    };
}
#endif
/* sample run:

*/
