/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #3
 * Sat Sep  2 15:47:28 PDT 2017
 * Goal: Implement a guessing game. The user must think of a number between
 * between 1 and 100, inclusive. The program will make guesses and the user
 * will tell the program to guess higher or lower.
 */

#include <iostream>
using namespace std;


/* This function will prompt the user to respond with a hint based on
* the paramter 'guess'. The user input is stored in the parameter 'result'.
*/
void getUserResponseToGuess(int guess, char& result){
    cout << "is it "<< guess << " (h/l/c)? ";
    cin >> result ;
}

/* This function returns a whole number that is 1/2 the difference of
* the integer parameters 'low' and 'high'. This function TRUNCATES, or
* always returns the lower of possibilities in the response.
*/
int getMidpoint(int low, int high){
    return (high - low) / 2;
}

/* This function implements the core of the game. The game performs a
* binary seach for the number our player has selected.
* No parameters or return values.
*/
void playOneGame(){
    // change these values to adjust the range of the game
    int min = 1; // this sets the starting and current minimum value
    int max = 100;  // this sets the starting and current maximum value

    int guess = 0 ; // the current guess
    char result;    // stores user input

    cout << "Think of a number between " << min << " and " << max << ".\n";
    // opening up the range to be inclusive
    min -=1 ;
    max +=1 ;
    do {
        guess = min + getMidpoint(min, max);
        getUserResponseToGuess(guess,result);
        // set the min or max to the last guess based on the user's input
        if (result == 'h'){
            min = guess ;
        } else if (result == 'l') {
            max = guess;
        } // invalid input will loop here without doing anything
    } while (result != 'c');
}


/* main has the primary loop for controlling repeated runs of the game.
*
*/
int main(){ // using the provided main
    char response;

    cout << "Ready to play (y/n)? ";
    cin >> response;
    while (response == 'y') {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
}

/* Commented run: test numbers will be 81, 37, 5 and 45
Ready to play (y/n)? y
Think of a number between 1 and 100.
is it 50 (h/l/c)? h
is it 75 (h/l/c)? h
is it 88 (h/l/c)? l
is it 81 (h/l/c)? c
Great! Do you want to play again (y/n)? y
Think of a number between 1 and 100.
is it 50 (h/l/c)? l
is it 25 (h/l/c)? h
is it 37 (h/l/c)? c
Great! Do you want to play again (y/n)? y
Think of a number between 1 and 100.
is it 50 (h/l/c)? l
is it 25 (h/l/c)? l
is it 12 (h/l/c)? l
is it 6 (h/l/c)? l
is it 3 (h/l/c)? h
is it 4 (h/l/c)? h
is it 5 (h/l/c)? c
Great! Do you want to play again (y/n)? y
Think of a number between 1 and 100.
is it 50 (h/l/c)? l
is it 25 (h/l/c)? h
is it 37 (h/l/c)? h
is it 43 (h/l/c)? h
is it 46 (h/l/c)? l
is it 44 (h/l/c)? h
is it 45 (h/l/c)? c
Great! Do you want to play again (y/n)? n
mdavis@jarvis:~/school/cis278$
*/
