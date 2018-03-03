/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #16.2
 * Sun Dec  3 18:08:47 PST 2017
 * Goal:use the previously developed myString class to
 * gather user input and determin if the user hase provided a
 * palindrome, ignoring whitespace and punctuation.
 */

#include <iostream>
// #include <cstring>
#include <cctype>

#include "mystring.h"

using namespace std;
using namespace cs_mystring;

bool isAPalindrome(MyString inString, int min, int max);
string boolString(bool convertMe);

int main()
{
    const MyString strs[] = {
        MyString("TaCocat"),
        MyString("tacorcat"),
        MyString("tacocat!"),
        MyString("!tacocat"),
        MyString("taco cat"),
        MyString("taco, cat"),
        MyString("taco, gato")
    };

    for (int i = 0; i!=7; ++i){
        cout << strs[i] << " : "
        << boolString(isAPalindrome(strs[i],0,strs[i].length()-1))
        << endl;
    }
}






//
bool isAPalindrome(MyString inString, int min, int max){
    // need to solve the special character problem before we test
    // for equality.
    if (ispunct(inString[min]) || isspace(inString[min])){
        return(isAPalindrome(inString, min +1, max));
    } else if (ispunct(inString[max]) || isspace(inString[max])){
        return(isAPalindrome(inString, min, max -1));
    } else if (toupper(inString[min]) == toupper(inString[max])){
        if (min < max){
            return (isAPalindrome(inString, min +1, max -1));
        }
    } else {
        return false;
    }
}






string boolString(bool convertMe) {
    if (convertMe) {
        return "true";
    } else {
        return "false";
    }
}

/* sample run:
*/
