/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #1
 * Sun Aug 20 21:28:19 PDT 2017
 * Goal: a program that asks the user to enter a date in the format specified
 * (month/day/2-digit-year). The program should then determine whether
 * the month times the day is equal to the year. If so, it should display a
 * message saying the date is magic. Otherwise it should display a message saying
 * the date is not magic.
 */

#include <iostream>
using namespace std;

int main(){
    // required variables
    char slash = '/'; // delimiter to tokenize on
    int month,  // int from user inpot for MM
        day,    // int from user input for DD
        year;   // int from user input for YY

    // prompt the user for input
    cout << "Enter a date in MM/DD/YY format to see if it is \"magic\": ";
    // cut the input up into 3 ints, separated by slashes
    cin >> month >> slash >> day >> slash >> year;
    // multiply month times day and compare it to year
    if (month * day == year ){
        // inform user of the magic nature of the date
        cout << "The date input is magic." << endl;
    } else {
        // inform the user of the non magic nateure of the date
        cout << "The date input is not magic." << endl;
    }

}
/* Commented run:
mdavis@jarvis:~/school/cis278$ ./a1_1
Enter a date in MM/DD/YY format to see if it is "magic": 2/10/20
The date input is magic.
mdavis@jarvis:~/school/cis278$ ./a1_1
Enter a date in MM/DD/YY format to see if it is "magic": 02/04/08
The date input is magic.
mdavis@jarvis:~/school/cis278$ ./a1_1
Enter a date in MM/DD/YY format to see if it is "magic": 4/1/98
The date input is not magic.
mdavis@jarvis:~/school/cis278$ ./a1_1
Enter a date in MM/DD/YY format to see if it is "magic": 04/01/98
The date input is not magic.
*/
