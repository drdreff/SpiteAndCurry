/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #4
 * Sat Sep  9 10:36:24 PDT 2017
 * Goal: Implement a simplified poker hand evaluation program. It will take
 * 5 cards (2-9) as input, analyze them and print the highest ranking hand
 * that can be made with those cards. Without suits, we're ignoring all flush
 * possibilities. In descending order the hands are: four of a kind, full
 * house, straight, trips, two-pair, pair, high card.
 */

#include <iostream>
using namespace std;

// prototypes
bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);
void pivotArray(const int hand[], int (&pivot)[10]);
int countPairs(const int hand[]);
int countTrips(const int hand[]);

/* main only needs to collect input and control the flow of our tests.
 * The hand will be evaluated in ascending rank of hand value, except
 * "high card".
 */
int main(){

    int hand[5]; // to hold our cards

    // first get the five cards that will be the hand
    cout << "Enter five numeric cards, no face cards. Use 2 - 9." << endl;
    // load user input into each (int) element
    for (int index = 0; index < 5 ; index++){
        cout << "Card " << index +1 << ": ";
        cin >> hand[index];
    }
    // test the hand to see if it is better than 'high card'
    if (containsPair(hand)){
        cout << "Pair!";
    } else if (containsTwoPair(hand)){
        cout << "Two Pair!";
    } else if (containsThreeOfaKind(hand)){
        cout << "Three of a Kind!";
    } else if (containsStraight(hand)){
        cout << "Straight!";
    } else if (containsFullHouse(hand)){
        cout << "Full House!";
    } else if (containsFourOfaKind(hand)){
        cout << "Four of a kind!";
    } else {
        // every hand has a "high" card
        cout << "High Card!";
    }
    cout << endl;
}

/* This function pivots an array. The inputs must be an integer array, and a
 * reference to an array to store the pivoted form. The index of the
 * pivot array will match the value of the integer being counted.
 */
void pivotArray(const int ary[5], int (&pivot)[10]){
    // increment the count of occurrences.
    for (int index =0; index < 5; index ++ ){
        pivot[ary[index]] ++;
    }
}

/* countPairs takes an integer array as input and returns the number of pairs
 * of integers found. This should be called whenever looking for pairs of
 * duplicated ints in the array.
 */
int countPairs(const int hand[]){

    int pivot[10] = {0}; // to analyze the hand
    int pairs = 0;     // to count the number of pairs

    pivotArray(hand, pivot);
    for ( int index = 2; index < 10 ; index ++ ){
        if (pivot[index] == 2 ){
            pairs ++;
        }
    }
    return pairs;
}

/* countTrips returns the number of cards that have 3 of any one card in
* the hand. It uses the pivotArray function to find the duplicated cards.
*/
int countTrips(const int hand[]){

    int pivot[10] = {0}; // to analyze the hand
    int trips = 0;  // Holds the return value

    pivotArray(hand, pivot);
    for ( int index = 2; index < 10 ; index ++ ){
        // walk through the pivoted array looking for '3'
        if (pivot[index] == 3 ){
            // return true; // short circuit removed for clarity
            trips ++;
        }
    }
    return trips;
}
/* This function will return true ONLY if there are exactly 2 of any
 * card. This function can be called to check for full house, but not for
 * any other hand.
 */
bool  containsPair(const int hand[]){
    return (countPairs(hand) == 1 && countTrips(hand) == 0);
}

/* Checks for two pairs of cards. It calls pivotArray to find any duplicated
 * cards.
 */
bool  containsTwoPair(const int hand[]){
    return (countPairs(hand) == 2) ;
}

/* containsThreeOfaKind returns true only if there are 3 of any one card in
 * the hand and there are no pairs. It uses the countTrips and countPairs.
 */
bool  containsThreeOfaKind(const int hand[]){
    return (countTrips(hand) == 1  && countPairs(hand) == 0);
}

/* containsStraight retuns true if there are 5 cards in an unbroken sequence.
 * It calls pivotArray to make the analysis easier. With 2-9 there's only 4
 * hands that are possible to create a straight.
 */
bool  containsStraight(const int hand[]){

    int pivot[10] = {0};      // to analyze the hand
    int sequentialCards = 0;  // Counter to track cards in sequence

    pivotArray(hand, pivot);

    // walk up the array, +1 to counter when we have a card, reset at a gap
    for ( int index = 2; index < 10 ; index ++ ){
        // walk through the pivoted array looking for cards
        if (pivot[index] == 1 ){
            // we have a card, add one to the counter
            sequentialCards ++;
        } else if (sequentialCards > 0 && sequentialCards < 5 ) {
            // Reset the counter, this is a gap
            sequentialCards = 0 ;
        }
    }
    return (sequentialCards == 5);
}

/* containsFullHouse returns true only if there is a pair *and* a 3 of a kind.
 * It uses the containsThreeOfaKind and containsPair functions, which both must
 * return true for this function to return true.
 */
bool  containsFullHouse(const int hand[]){
    return (countPairs(hand) == 1 && countTrips(hand) ==1);
}

/* containsFourOfaKind returns true only if there are 4 of any one card in
 * the hand. It uses the pivotArray function to find the duplicated cards.
 */
bool  containsFourOfaKind(const int hand[]){

    int pivot[10] = {0}; // to analyze the hand
    bool quads = false;  // Holds the return value

    pivotArray(hand, pivot);
    for ( int index = 2; index < 10 ; index ++ ){
        // walk through the pivoted array looking for '4'
        if (pivot[index] == 4 ){
            // return true; // short circuit removed for clarity
            quads = true;
        }
    }
    return quads;
}
/* Commented runs:
mdavis@jarvis:~/school/cis278$ g++ a4_1.cpp -o a4_1 && ./a4_1
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 8
Card 2: 7
Card 3: 8
Card 4: 2
Card 5: 7
Two Pair!
mdavis@jarvis:~/school/cis278$ ./a4_1
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 8
Card 2: 7
Card 3: 4
Card 4: 6
Card 5: 5
Straight!
mdavis@jarvis:~/school/cis278$ ./a4_1
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 9
Card 2: 2
Card 3: 3
Card 4: 4
Card 5: 5
High Card!
mdavis@jarvis:~/school/cis278$ ./a4_1
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 3
Card 2: 4
Card 3: 5
Card 4: 6
Card 5: 7
Straight!
mdavis@jarvis:~/school/cis278$ ./a4_1
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 2
Card 2: 2
Card 3: 4
Card 4: 2
Card 5: 2
Four of a kind!
mdavis@jarvis:~/school/cis278$ ./a4_1
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 5
Card 2: 4
Card 3: 5
Card 4: 7
Card 5: 5
Three of a Kind!
mdavis@jarvis:~/school/cis278$ ./a4_1
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 6
Card 2: 5
Card 3: 6
Card 4: 5
Card 5: 6
Full House!
mdavis@jarvis:~/school/cis278$ ./a4_1
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 4
Card 2: 5
Card 3: 6
Card 4: 7
Card 5: 4
Pair!

*/
