/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #13.1 implementation
 * Sun Nov 12 11:07:13 PST 2017
 * Goal: Define syntactically correct classes that use dynamic memory in
 * accordance with good programming practice. Explain the "Big-Three" member
 * functions that are required when a class uses dyamic memory.

 CLASS INVARIANT:

The class has one private data member defined as follows:

char *str;

str always represents a valid null-terminated c-string
 */
#include <iostream>
#include <cassert>
#include <cstring>

#include "mystring.h"
using namespace std;

namespace cs_mystring {

    // this controls the max size of >> and read() input buffers
    static const int BUFFER_SIZE = 127;

    MyString::MyString(){
        pstring = new char[1];
        strcpy(pstring, "");
    }






    MyString::MyString(const char* inString){
        pstring = new char[strlen(inString)+1];
        strcpy(pstring, inString);
    }






    MyString::MyString(const MyString& right){
        pstring = new char[strlen(right.pstring)+1];
        strcpy(pstring, right.pstring);
    }






    MyString::~MyString(){
        delete [] pstring;
    }






    int MyString::length() const {
        return strlen(pstring);
    }






    std::ostream& operator<<(std::ostream& out, const MyString& right){
        out << right.pstring;
        return out;
    }






    std::istream& operator>>(std::istream& in, MyString& right){
        while (isspace(in.peek())){
            in.ignore();
        }
        char *temp = new char[BUFFER_SIZE];
        in >> temp;
        right = temp;
        delete [] temp;
        return in;
    }






    bool operator<(const MyString& left,const MyString& right){
        return (strcmp(left.pstring,right.pstring) < 0 );
    }






    bool operator>(const MyString& left,const MyString& right){
        return (strcmp(left.pstring,right.pstring) > 0 );
    }






    bool operator==(const MyString& left,const MyString& right){
        return (strcmp(left.pstring,right.pstring) == 0 );
    }






    bool operator!=(const MyString& left, const MyString& right){
        return strcmp(left.pstring, right.pstring) != 0;
    }






    bool operator<=(const MyString& left,const MyString& right){
        return (strcmp(left.pstring,right.pstring) <= 0 );
    }






    bool operator>=(const MyString& left,const MyString& right){
        return (strcmp(left.pstring,right.pstring) >= 0 );
    }






    MyString MyString::operator=(const MyString& right){
        if (this != &right ){
            strcpy(pstring, right.pstring);
        }
        return *this;
    }






    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(pstring));
        return pstring[index];
    }






    char& MyString::operator[](int index){
        assert(index >= 0 && index < strlen(pstring));
        return pstring[index];
    }






    MyString operator+(const MyString& left, const MyString& right){
        char *temp = new char[left.length()+right.length()+1];
        strcpy(temp,left.pstring);
        strcat(temp,right.pstring);
        MyString *newString = new MyString(temp);
        delete [] temp;
        return *newString;
    }






    MyString MyString::operator+=(const MyString& right){
        *this = *this + right;
        return *this;
    }






    void MyString::read(std::istream& in, const char delim ){
        char *temp = new char[BUFFER_SIZE];
        in.getline(temp, 127, delim);
        delete [] this->pstring;
        this->pstring = new char[strlen(temp) + 1];
        strcpy(this->pstring, temp);
        delete [] temp;
    }
}
