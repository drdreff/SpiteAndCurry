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

int main()
{
    MyString input; // to hold user input

    while (input != "quit"){
        cout << "Enter a string: ";
        input.read(cin, '\n');
        // as long as the user wants to test strings
        if (input != "quit"){
            cout << input << " ";
            if (isAPalindrome(input, 0,input.length()-1)){
                cout << "is";
            } else {
                cout << "is not";
            }
            cout << " a palindrome." << endl;
        }
    }
}






// isAPalindrome analyzes a substring to determine if it is a palindrome.
// It operates recursively to check if the characters at indeces min and max
// are equal. It will ignore punctuation and whitespace.
bool isAPalindrome(MyString inString, int min, int max){
    // call again after skipping a punctuation or space in the min index.
    if (ispunct(inString[min]) || isspace(inString[min])){
        return(isAPalindrome(inString, min +1, max));

    // call again after skipping a punctuation or space in the min index.
    } else if (ispunct(inString[max]) || isspace(inString[max])){
        return(isAPalindrome(inString, min, max -1));

    // call again if the min and max characters are equal
    } else if (toupper(inString[min]) == toupper(inString[max])){
         if (min < max){
             return (isAPalindrome(inString, min +1, max -1));
        } else {
            // we've reached the center
            return true;
        }
    } else {
        // default case
        return false;
    }
}

/* sample run:
mdavis@jarvis:~/school/cis278/a16$ g++ a16_2.cpp mystring.cpp -o a16_2 && ./a16_2
Enter a string: Able was I, ere I saw Elba
Able was I, ere I saw Elba is a palindrome.
Enter a string: peanut butter
peanut butter is not a palindrome.
Enter a string: Taco Cat
Taco Cat is a palindrome.
Enter a string: Taco Cat!
Taco Cat! is a palindrome.
Enter a string: !!Taco, Cat
!!Taco, Cat is a palindrome.
Enter a string: quit
mdavis@jarvis:~/school/cis278/a16$
*/
