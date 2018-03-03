/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #16.1
 * Sun Dec  3 18:08:47 PST 2017
 * Goal: Write a recursive function tht accepts an array of characters,
 * min and max array indices. The function reverses the order of the
 * characters between the two bounds, inclusively.
 */
#include <iostream>
#include <cstring>
using namespace std;

void reverseWithinBounds(char* inString, int min, int max);
void reverseCstring(char* inString);

int main()
{
    char test[] = "Facebook!";
    char test1[] = "Facebook!";
    char test2[] = "Many letters Reversed!";

    // check reversing teh whole string
    reverseWithinBounds(test, 0, 8);
    // should print "!koobecaF"
    cout << test << endl;

    // check a zero case (base case)
    reverseWithinBounds(test1, 0, 0);
    // should print "Facebook!"
    cout << test1 << endl;

    // check a middle letter (base case)
    reverseWithinBounds(test1, 5, 5);
    // should print "Facebook!"
    cout << test1 << endl;

    // check min > max (base case)
    reverseWithinBounds(test1, 5, 1);
    // should print "Facebook!"
    cout << test1 << endl;

    // rotate around the center
    reverseWithinBounds(test1, 3, 5);
    // should print "Facobeok!"
    cout << test1 << endl;

    // reverse a longer string with spaces
    reverseCstring(test2);
    // should print "!desreveR srettel ynaM"
    cout << test2 << endl;
}






// recursively swaps characters from inString based on the indexes
// of min and max.
// min and max are incremented and decremented with each recursive
// call as long as min is less than max. There are no bounds checked,
// the caller must stay within bounds.
void reverseWithinBounds(char* inString, int min, int max){
    if (min < max){
        swap(inString[min],inString[max]);
        reverseWithinBounds(inString, min +1, max -1);
    }
}






// determines the length of the Cstring and calls reverseWithinBounds
// using 0 as the min and the length -1 as max.
void reverseCstring(char* inString){
    reverseWithinBounds(inString, 0, strlen(inString) -1);
}
/* sample run:
mdavis@jarvis:~/school/cis278/a16$ g++ a16_1.cpp -o a16_1 && ./a16_1
!koobecaF
Facebook!
Facebook!
Facebook!
Facobeok!
!desreveR srettel ynaM
mdavis@jarvis:~/school/cis278/a16$
*/
