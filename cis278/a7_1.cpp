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

    char empty[] = "";  // empty string for tests
    char empty2[] = ""; // control empty string

    // test lastIndexOf:
    char test1[] = "Facebook!";
    cout << "lastIndexOf:first character (pass): ";
    assertTrue(lastIndexOf(test1,'F') == 0 );

    cout << "lastIndexOf:last character (pass): ";
    assertTrue(lastIndexOf(test1,'!') == 8);

    cout << "lastIndexOf:multiple hits (pass): ";
    assertTrue(lastIndexOf(test1,'o') == 6);

    cout << "lastIndexOf:no hit (pass): ";
    assertTrue(lastIndexOf(test1,'z') == -1);

    cout << "lastIndexOf:case sensitivity (pass): ";
    assertTrue(lastIndexOf(test1,'f') == -1);

    cout << "lastIndexOf:empty string (pass): ";
    assertTrue(lastIndexOf(empty,'a') == -1);

    // test reverse:
    cout << "reverse:even number (pass): ";
    char test2[] = "Reverser";
    reverse(test2);
    assertTrue(stringCompare(test2,"resreveR"));

    cout << "reverse:odd number (pass): ";
    char test3[] = "Seven";
    reverse(test3);
    assertTrue(stringCompare(test3,"neveS"));

    cout << "reverse:special characters (pass): ";
    char test4[] = "Spite & Curry!";
    reverse(test4);
    assertTrue(stringCompare(test4,"!yrruC & etipS"));

    cout << "reverse:empty string (pass): ";
    reverse(empty);
    assertTrue(stringCompare(empty,empty2));

    // test replace:
    char test5[] = "Spite & Curry!";
    cout << "replace:single hit (pass): ";
    replace(test5, 'p', 'l');
    assertTrue(stringCompare(test5, "Slite & Curry!"));

    cout << "replace:multiple hit (pass): ";
    replace(test5, 'r', 't');
    assertTrue(stringCompare(test5, "Slite & Cutty!"));

    cout << "replace:zero hits (pass): ";
    replace(test5, 'z', 'f');
    assertTrue(stringCompare(test5, "Slite & Cutty!"));

    cout << "replace:case change (pass): ";
    replace(test5, 'S', 's');
    replace(test5, 'C', 'c');
    assertTrue(stringCompare(test5, "slite & cutty!"));

    cout << "replace:case sensitivity (pass): ";
    replace(test5, 'T', 'z');
    assertTrue(stringCompare(test5, "slite & cutty!"));

    cout << "replace:specials (pass): ";
    replace(test5, ' ', '.');
    assertTrue(stringCompare(test5, "slite.&.cutty!"));

    cout << "replace:empty string (pass): ";
    replace(empty, '\0', '.');
    assertTrue(stringCompare(empty, empty2));

    // test isPalindrome:
    cout << "isPalindrome:valid palindrome (pass): ";
    char ptest1[] = "tacocat";
    assertTrue(isPalindrome(ptest1));

    cout << "isPalindrome:not a palindrome (fail): ";
    char ptest2[] = "notapalindrome";
    assertTrue(isPalindrome(ptest2));

    cout <<"isPalindrome:palindrome with specials (pass): ";
    char ptest3[] = "avid diva";
    assertTrue(isPalindrome(ptest3));

    cout << "isPalindrome:palindrome broken by specials (fail): ";
    char ptest4[] = "taco cat";
    assertTrue(isPalindrome(ptest4));

    cout << "isPalindrome:case insensitive palindrome (pass): ";
    char ptest5[] = "TacoCat";
    assertTrue(isPalindrome(ptest5));

    cout << "isPalindrome:even number (pass): ";
    char ptest6[] = "avid--diva";
    assertTrue(isPalindrome(ptest6));

    cout << "isPalindrome:odd number (pass): ";
    char ptest7[] = "Aibohphobia";
    assertTrue(isPalindrome(ptest7));

    cout << "isPalindrome:empty (pass): ";
    assertTrue(isPalindrome(empty));

    // test toupper:
    cout << "toupper:all lower (pass): ";
    char test6[] = "lowercase";
    toupper(test6);
    assertTrue(stringCompare(test6,"LOWERCASE"));

    cout << "toupper:mixed case (pass): ";
    char test7[] = "CamelOrMixedCase";
    toupper(test7);
    assertTrue(stringCompare(test7,"CAMELORMIXEDCASE"));

    cout << "toupper:all upper (pass): ";
    toupper(test7);
    assertTrue(stringCompare(test7,"CAMELORMIXEDCASE"));

    cout << "toupper:specials (pass): ";
    char test8[] = "Sp3cials & Numb3rs";
    toupper(test8);
    assertTrue(stringCompare(test8,"SP3CIALS & NUMB3RS"));

    cout << "toupper:empty string (pass): ";
    toupper(empty);
    assertTrue(stringCompare(empty,empty2));

    // test numLetters:
    cout << "numLetters:all letters (pass): ";
    assertTrue(numLetters(test7) == 16);

    cout << "numLetters:no letters (pass): ";
    char test9[] ="!@#$\%^&*()1234567";
    assertTrue(numLetters(test9) == 0);

    cout << "numLetters:one letter (pass): ";
    char test10[] = "A1234^()";
    assertTrue(numLetters(test10) == 1);

    cout << "numLetters:mixed case (pass): ";
    char test11[] = "AnoTherT3st!";
    assertTrue(numLetters(test11) == 10);

    cout << "numLetters:empty string (pass): ";
    assertTrue(numLetters(empty) == 0);
}






/* this will output "PASS" or "FAIL" if the value is "True" or "False"
 * respectively. This is a rudimentary unit test function.
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

    int length = strlen(inString) -1; // Index of the last element

    for (int i = 0; i < length - i ; i++){
        swap(inString[i],inString[ length - i ]);
    }
}






/* This function finds all instances of the char 'target' in the string and
 * replace them with 'replacementChar'. It returns the number of replacements
 * that it makes. Returns 0 if no replacements are made.
 */
int replace(char* inString, char target, char replacementChar){

    int index =0; // to walk up the array
    int replacements =0; // to walk up the array

    while (inString[index] != '\0'){
        if (inString[index] == target){
            inString[index] = replacementChar;
            replacements ++;
        }
        index++;
    }
    return replacements;
}






/* This function returns true if the argument string is a palindrome.
 * It returns false if it is no. Palindromes are symmetrical word structures,
 * this one is more strict about whitespace (eg "tacocat" and "taco cat") but is
 * not case sensitive. It will also return as soon as it detects that the
 * string is not palindromic.
 */
bool isPalindrome(const char* inString){

    int length = strlen(inString) -1;
    int i = 0;  // iterator for counting up
    bool condition = true;
    
    while (condition && i < length - i){
        condition = (toupper(inString[i]) == toupper(inString[ length - i ]));
        i ++;
    }

    return condition;
}







/* This function converts the c-string parameter to all uppercase. It calls the
 * char toupper to convert each character in the array.
 */
void toupper(char* inString){
    int i =0; // iterator

    while (inString[i] != '\0'){
        inString[i] = toupper(inString[i]);
        i++;
    }
}






/* This function returns the count of alphabetic characters in the string. It
 * uses the char isalpha to count the letters.
 */
int numLetters(const char* inString){
    int count =0; // to hold the number of letters counted
    int i =0; // to count up the array

    // while loop guarantees that we don't count the ''\0'
    while (inString[i] != '\0'){
        if (isalpha(inString[i])){
            count ++;
        }
        i++;
    }
    return count;
}

/* commented test run:
mdavis@jarvis:~/school/cis278$ ./a7_1
lastIndexOf:first character (pass): PASS
lastIndexOf:last character (pass): PASS
lastIndexOf:multiple hits (pass): PASS
lastIndexOf:no hit (pass): PASS
lastIndexOf:case sensitivity (pass): PASS
lastIndexOf:empty string (pass): PASS
reverse:even number (pass): PASS
reverse:odd number (pass): PASS
reverse:special characters (pass): PASS
reverse:empty string (pass): PASS
replace:single hit (pass): PASS
replace:multiple hit (pass): PASS
replace:zero hits (pass): PASS
replace:case change (pass): PASS
replace:case sensitivity (pass): PASS
replace:specials (pass): PASS
replace:empty string (pass): PASS
isPalindrome:valid palindrome (pass): PASS
isPalindrome:not a palindrome (fail): FAIL
isPalindrome:palindrome with specials (pass): PASS
isPalindrome:palindrome broken by specials (fail): FAIL
isPalindrome:case insensitive palindrome (pass): PASS
isPalindrome:even number (pass): PASS
isPalindrome:odd number (pass): PASS
isPalindrome:empty (pass): PASS
toupper:all lower (pass): PASS
toupper:mixed case (pass): PASS
toupper:all upper (pass): PASS
toupper:specials (pass): PASS
toupper:empty string (pass): PASS
numLetters:all letters (pass): PASS
numLetters:no letters (pass): PASS
numLetters:one letter (pass): PASS
numLetters:mixed case (pass): PASS
numLetters:empty string (pass): PASS
mdavis@jarvis:~/school/cis278$
*/
