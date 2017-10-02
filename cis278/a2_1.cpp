/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #2
 * Sun Aug 27 10:20:19 PDT 2017
 * Goal: Write a command line game that plays a simple version of blackjack.
 * The program generates a random number between 1 and 10 each time the
 * player gets a card. We keep a running total of the player's
 * cards, and ask the player whether or not we should deal another card.
 * If the player hits 21 exactly, the program should print "Congratulations!"
 * and then ask if the player wants to play again. If the player exceeds 21,
 * the program should print "Bust" and then ask if the player wants to play
 * again.
  */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    // required variables
    srand(static_cast<unsigned>(time(0))); // seeding random
    char player_input; // player decisions
    int hand,  // total of all cards
        card,  // current card
        initial_hand = 2;   // number of cards to start with

    do { // until player enters 'n'...
        // prompt the user for input
        cout << "First cards: ";
        hand = 0;
        for (int i = 0; i < initial_hand ; i++ ){
            card = 1+ rand() % 10; //  cards 1-10
            cout << card;
            hand += card;
            if (i < initial_hand -1 ) {
                cout << ", ";
            }
        }
        cout << endl << "Total: " << hand << endl;
        while (hand < 21 && toupper(player_input) != 'N') {
            do { // until we get valid input...
                cout << "Do you want another card? (y/n):";
                cin >> player_input;
            } while (toupper(player_input) != 'N' && toupper(player_input) != 'Y');
            if ( toupper(player_input) != 'N'){
                card = 1 + rand() % 10; //  cards 1-10
                hand += card;
                cout << "Card: " << card << endl;
            }
            cout << "Total: " << hand << endl;
            if (hand > 21 ){ // player has busted
                cout << "Bust." << endl;
                player_input ='N'; // no more cards
            } else if ( hand == 21 ){ // player has won
                cout << "Congratulations!" << endl;
                player_input ='N'; // no more cards
            }
        }
        do { // until we get valid input...
            cout << "Would you like to play again? (y/n): ";
            cin >> player_input;
        } while (toupper(player_input) != 'N' && toupper(player_input) != 'Y');
    }  while (toupper(player_input) != 'N');

}
/* Commented run:
First cards: 1, 3
Total: 4
Do you want another card? (y/n):y
Card: 8
Total: 12
Do you want another card? (y/n):y
Card: 10
Total: 22
Bust.
Would you like to play again? (y/n): y
First cards: 7, 1
Total: 8
Do you want another card? (y/n):y
Card: 4
Total: 12
Do you want another card? (y/n):y
Card: 4
Total: 16
Do you want another card? (y/n):y
Card: 2
Total: 18
Do you want another card? (y/n):h
Do you want another card? (y/n):y
Card: 2
Total: 20
Do you want another card? (y/n):y
Card: 6
Total: 26
Bust.
Would you like to play again? (y/n): y
First cards: 9, 1
Total: 10
Do you want another card? (y/n):y
Card: 7
Total: 17
Do you want another card? (y/n):n
Total: 17
Would you like to play again? (y/n): y
First cards: 5, 1
Total: 6
Do you want another card? (y/n):y
Card: 5
Total: 11
Do you want another card? (y/n):y
Card: 1
Total: 12
Do you want another card? (y/n):y
Card: 10
Total: 22
Bust.
Would you like to play again? (y/n): y
First cards: 8, 6
Total: 14
Do you want another card? (y/n):y
Card: 9
Total: 23
Bust.
Would you like to play again? (y/n): y
First cards: 3, 7
Total: 10
Do you want another card? (y/n):y
Card: 7
Total: 17
Do you want another card? (y/n):y
Card: 10
Total: 27
Bust.
Would you like to play again? (y/n): y
First cards: 7, 2
Total: 9
Do you want another card? (y/n):y
Card: 3
Total: 12
Do you want another card? (y/n):y
Card: 3
Total: 15
Do you want another card? (y/n):y
Card: 7
Total: 22
Bust.
Would you like to play again? (y/n): y
First cards: 3, 5
Total: 8
Do you want another card? (y/n):y
Card: 4
Total: 12
Do you want another card? (y/n):y
Card: 4
Total: 16
Do you want another card? (y/n):y
Card: 2
Total: 18
Do you want another card? (y/n):y
Card: 4
Total: 22
Bust.
Would you like to play again? (y/n): y
First cards: 7, 7
Total: 14
Do you want another card? (y/n):y
Card: 6
Total: 20
Do you want another card? (y/n):y
Card: 9
Total: 29
Bust.
Would you like to play again? (y/n): y
First cards: 5, 4
Total: 9
Do you want another card? (y/n):y
Card: 1
Total: 10
Do you want another card? (y/n):y
Card: 1
Total: 11
Do you want another card? (y/n):y
Card: 9
Total: 20
Do you want another card? (y/n):y
Card: 1
Total: 21
Congratulations!
Would you like to play again? (y/n): n
mdavis@jarvis:~/school/cis278$
*/
