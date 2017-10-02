/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #7
 * Sun Oct  1 17:00:41 PDT 2017
 * Goal: write string handling libraries and tests for them
 */

#include <iostream>
#include <cstring>

using namespace std;

// prototypes
int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper(char* inString);
int numLetters(const char* inString);
void assertTrue(bool test);
bool stringCompare(const char* str1, const char* str2);






// main will test all of the string libs
int main(){

    // test lastIndexOf:
    char test1[] = "Facebook!";
    // first character (index 0)
    assertTrue(lastIndexOf(test1,'F') == 0 );

    // last character
    assertTrue(lastIndexOf(test1,'!') == 8);

    // multiple hits
    assertTrue(lastIndexOf(test1,'o') == 6);

    // no hit
    assertTrue(lastIndexOf(test1,'z') == -1);

    // case sensitivity
    assertTrue(lastIndexOf(test1,'f') == -1);

    // test reverse:
    char test2[] = "Reverser";
    char test2_A[] = "resreveR";
    char test3[] = "Words with Spaces & Stuff.";
    char test4[] = "foo";

    // even number
    reverse(test2);
    assertTrue(stringCompare(test2,test2_A));

    // odd number
    // special characters

    // test replace:
    // single hit
    // multiple hit
    // zero hits
    // case change
    // case sensitivity
    // specials

    // test isPalindrome:
    // valid palindrom
    // not a palindrome
    // palindrome with specials
    // palindrome broken by specials
    // case insensitive palindrome
    // even number
    // odd number

    // test toupper:
    // all lower
    // no lower
    // specials

    // test numLetters:
    // all letters
    // no letters
    // one letter
    // mixed case

}






/* this will output "PASS" or "FAIL" if the value is "True" or "False"
 * respectively. This is rudimentary unit test function.
 */
void assertTrue(bool test) {
    if (test)
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
}






/* stringCompare returns true if the two strings are exactly the same. The
 * logic allows for strings of different sizes to be compared. It will
 * return as soon as it finds a false case.
 */
bool stringCompare(const char* str1, const char* str2){

    int index=0;
    bool condition = true;

    // making this a do .. while ensures that we compare the null terminators
    do {
        condition = (str1[index] == str2[index]);
        index ++;
    } while (str1[index] != '\0' && condition);
    return condition ;
}






/* This function finds the last index where the target char can be found in the
 * string. It returns -1 if the target char does not appear in the string.
 * The function is case sensitive. This operates by walking up the array and
 * comparing the current element to the target element.
 */
int lastIndexOf(const char* inString, char target){
    int index = -1; // will contain the return value
    int counter = 0; // for walking up the array

    while ( inString[counter] != '\0') {
        if (inString[counter] == target){
            index = counter; // store the index where we found 'target'
        }
        counter++; // check the next one
    }
    return index;
}







/* This function alters any string that is passed by reversing the charaters
 * of the string. If "backward" gets passed in it will be reversed in place to
 * "drawkcab".
 */
void reverse(char* inString){
    int counter = strlen(inString) -1;
    for (int i = 0; i < counter - i ; i++){
        swap(inString[i],inString[ counter - i ]);
    }
}






/* This function finds all instances of the char 'target' in the string and
 * replace them with 'replacementChar'. It returns the number of replacements
 * that it makes. Returns 0 if no replacements are made.
 */
int replace(char* inString, char target, char replacementChar){

}






/* This function returns true if the argument string is a palindrome.
 * It returns false if it is no. Palindromes are symmetrical word structures,
 * this one is more strict about whitespace (eg "tacocat" and "taco cat") but is
 * not case sensitive.
 */
bool isPalindrome(const char* inString){

}






/* This function converts the c-string parameter to all uppercase
 */
void toupper(char* inString){

}






/* This function returns the count of alphabetic characters in the string.
 */
int numLetters(const char* inString){

}
