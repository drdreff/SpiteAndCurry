/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #13.1 implementation
 * Sun Nov 12 11:07:13 PST 2017
 * Goal: Define syntactically correct classes that use dynamic memory in
 * accordance with good programming practice. Explain the "Big-Three" member
 * functions that are required when a class uses dyamic memory.
 */
#include <iostream>
#include <cassert>
#include <cstring>

#include "mystring.h"
using namespace std;

namespace cs_mystring {

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






    // std::istream& operator>>(std::istream& in, MyString& right){
    //     in >> right.pstring;
    //     return in;
    // }






    bool operator<(const MyString& left,const MyString& right){
        bool result = false;
        if (strcmp(left.pstring,right.pstring) < 0 ){
            result = true;
        }
        return result;
    }






    bool operator>(const MyString& left,const MyString& right){
        return (strcmp(left.pstring,right.pstring) > 0 );
    }






    // bool operator==(const MyString& left,const MyString& right){
    //     bool result = false;
    //     if (strcmp(left.pstring,right.pstring) == 0 ){
    //         result = true;
    //     }
    //     return result;
    // }
    bool operator==(const MyString& left,const MyString& right){
        return (strcmp(left.pstring,right.pstring) == 0 );
    }







    // bool operator!=(const MyString& left,const MyString& right){
    //     bool result = true;
    //     if (left.length() == right.length() &&
    //         strcmp(left.pstring,right.pstring) == 0){
    //             result = false;
    //     }
    //     return result;
    // }
    bool operator!=(const MyString& left, const MyString& right)
    {
        return strcmp(left.pstring, right.pstring) != 0;
    }






    bool operator<=(const MyString& left,const MyString& right){
        bool result = false;
        if (strcmp(left.pstring,right.pstring) <= 0 ){
            result = true;
        }
        return result;
    }






    bool operator>=(const MyString& left,const MyString& right){
        bool result = false;
        if (strcmp(left.pstring,right.pstring) >= 0 ){
            result = true;
        }
        return result;
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

}
