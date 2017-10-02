/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #5
 * Sun Sep 17 17:52:39 PDT 2017
 * Goal: Develop a program that records high-score data for a fictitious game.
 * The user will enter five names, and five scores. The program will store the
 * data in memory, and print it as a sorted list, descending by score.
 */

#include <iostream>
using namespace std;

// prototypes
void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
int indexOfSmallest(const int list[], int startingIndex, int numItems);
void displayData(const string names[], const int scores[], int size);

// constants
int NUM_SCORES = 5;

/* main only creates arrays and calls the core functions
 */
int main(){

    int scores[NUM_SCORES] = {0};    // to hold the numerical scores
    int size = NUM_SCORES;           // to make up for the lack of array.len()
    string names[NUM_SCORES]; // to hold the player names

    // get user input into the arrays
    initializeArrays(names, scores, size);
    // sort the arrays
    sortData(names, scores, size);
    // print out the data
    displayData(names, scores, size);
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
mdavis@jarvis:~/school/cis278$ ./a5_1
Enter the name for score #1: Suzy
Enter the score for score #1: 600
Enter the name for score #2: Kim
Enter the score for score #2: 9900
Enter the name for score #3: Bob
Enter the score for score #3: 1012
Enter the name for score #4: Armando
Enter the score for score #4: 8000
Enter the name for score #5: Tim
Enter the score for score #5: 514

Top Scorers:
Kim: 9900
Armando: 8000
Bob: 1012
Suzy: 600
Tim: 514

mdavis@jarvis:~/school/cis278$ ./a5_1
Enter the name for score #1: Mark
Enter the score for score #1: 0983745
Enter the name for score #2: Jena
Enter the score for score #2: 087543
Enter the name for score #3: Matt
Enter the score for score #3: 089234
Enter the name for score #4: Chris
Enter the score for score #4: 768543
Enter the name for score #5: Jon
Enter the score for score #5: 8756234

Top Scorers:
Jon: 8756234
Mark: 983745
Chris: 768543
Matt: 89234
Jena: 87543

mdavis@jarvis:~/school/cis278$ ./a5_1
Enter the name for score #1: Nick
Enter the score for score #1: 99999
Enter the name for score #2: Jon
Enter the score for score #2: 100000
Enter the name for score #3: Matt
Enter the score for score #3: 110000
Enter the name for score #4: Chris
Enter the score for score #4: 120000
Enter the name for score #5: Jena
Enter the score for score #5: 130000

Top Scorers:
Jena: 130000
Chris: 120000
Matt: 110000
Jon: 100000
Nick: 99999

*/
