/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #6.2
 * Sun Sep 24 19:05:45 PDT 2017
 * Goal: Develop a program that records high-score data for a fictitious game.
 * The user will enter the number of scores, and that number names, and scores.
 * The program will store the data in memory, and print it as a sorted list,
 * descending by score.
 */

#include <iostream>
using namespace std;

// prototypes
void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
int indexOfSmallest(const int list[], int startingIndex, int numItems);
void displayData(const string names[], const int scores[], int size);

// constants

/* main creates arrays sized by user input and calls the core functions
 */
int main(){

    int size = 0;           // to store user input for table size

    cout << "How many scores will you enter?: ";
    cin >> size;

    string* names = new string[size];// to hold the player names
    int* scores = new int[size];// to hold the numerical scores

    // get user input into the arrays
    initializeArrays(names, scores, size);
    // sort the arrays
    sortData(names, scores, size);
    // print out the data
    displayData(names, scores, size);

    // clean up
    delete [] names;
    delete [] scores;
}






/* initializeArrays does all of the user input. The index of the elements
 * must match between the score and the names. The loop index will keep
 * the arrays in sync.
 */
void initializeArrays(string names[], int scores[], int size) {

    for (int index=0;index < size; index ++){
        cout << "Enter the name for score #" << index +1 << ": ";
        cin >> names[index];
        cout << "Enter the score for score #" << index +1 << ": ";
        cin >> scores[index];
    }
    cout << endl;
}






/* sortData will sort the data such that the highest score value wil be
 * stored in the highest indexed element of the array. This version uses a
 * selection sort that has been provided.
 */
void sortData(string names[], int scores[], int size){

    int targetIndex = 0 ; // target for swap().

    for (int index = 0; index < size - 1; index++){
        targetIndex = indexOfSmallest(scores, index, size);
        swap(names[targetIndex], names[index]);
        swap(scores[targetIndex], scores[index]);
    }
}






/* indexOfSmallest returns the index of the smallest value in a segment
 * of the array provided in 'list'. The array segment to search is controlled
 * by the parameters 'startingIndex' and 'numItems'.
 */
int indexOfSmallest(const int list[], int startingIndex, int numItems)
    {
        int targetIndex = startingIndex;

        for (int count = startingIndex + 1; count < numItems; count++){
            if (list[count] < list[targetIndex]){
                targetIndex = count;
            }
        }

        return targetIndex;
}






/* displayData walks through the arrays starting at the end and prints the
 * values of both arrays.
 */
 void displayData(const string names[], const int scores[], int size){
     cout << "Top Scorers:" << endl;
     for (int index = size -1 ;index > -1 ; index --){
        cout << names[index] << ": " << scores[index] << endl;
     }
     cout << endl;
 }


/* Commented runs:
mdavis@kali:~/school/cis278$ ./a6_2
How many scores will you enter?: 4
Enter the name for score #1: Suzy
Enter the score for score #1: 990
Enter the name for score #2: Kim
Enter the score for score #2: 1000000
Enter the name for score #3: Armando
Enter the score for score #3: 822
Enter the name for score #4: Tim
Enter the score for score #4: 514

Top Scorers:
Kim: 1000000
Suzy: 990
Armando: 822
Tim: 514

mdavis@kali:~/school/cis278$ ./a6_2
How many scores will you enter?: 6
Enter the name for score #1: Nick
Enter the score for score #1: 11
Enter the name for score #2: Jon
Enter the score for score #2: 16
Enter the name for score #3: Matt
Enter the score for score #3: 19
Enter the name for score #4: Chris
Enter the score for score #4: 22
Enter the name for score #5: Jena
Enter the score for score #5: 42
Enter the name for score #6: Mark
Enter the score for score #6: 45

Top Scorers:
Mark: 45
Jena: 42
Chris: 22
Matt: 19
Jon: 16
Nick: 11

mdavis@kali:~/school/cis278$

*/
