/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #8.1
 * Sun Oct  8 16:26:53 PDT 2017
 * Goal: Develop a program that records high-score data for a fictitious game.
 * The user will enter the number of scores, and that number names, and scores.
 * The program will store the data in memory, and print it as a sorted list,
 * descending by score. This version uses a structure to collect the data.
 */

#include <iostream>
#include <cstring>

using namespace std;

// constants
const int MAX_NAME_SIZE = 24;

// Data Structures
struct highscore {
    char name[MAX_NAME_SIZE];
    int score;
};

// prototypes
void initializeData(highscore scores[], int size);
void displayData(const highscore scores[], int size);
void sortData(highscore scores[], int size);
int indexOfSmallest(const highscore scores[], int startingIndex, int numItems);

/* main creates arrays sized by user input and calls the core functions
 */
int main(){

    int size = 0;           // to store user input for table size

    cout << "How many scores will you enter?: ";
    cin >> size;

    highscore* scores = new highscore[size];// to hold the names and scores

    // get user input into the arrays
    initializeData(scores, size);
    // sort the arrays
    sortData(scores, size);
    // print out the data
    displayData(scores, size);

    // clean up
    delete [] scores;
}






/* initializeArrays does all of the user input. The index of the elements
 * must match between the score and the names. The loop index will keep
 * the arrays in sync.
 */
void initializeData(highscore scores[], int size) {

    for (int index=0;index < size; index ++){
        cin.ignore();
        cout << "Enter the name for score #" << index +1 << ": ";
        cin >> scores[index].name;
        cout << "Enter the score for score #" << index +1 << ": ";
        cin >> scores[index].score;
    }
    cout << endl;
}






/* sortData will sort the data such that the highest score value wil be
 * stored in the highest indexed element of the array. This version uses a
 * selection sort that has been provided.
 */
 void sortData(highscore scores[], int size){

    int targetIndex = 0 ; // target for swap().

    for (int index = 0; index < size - 1; index++){
        targetIndex = indexOfSmallest(scores, index, size);
        swap(scores[targetIndex], scores[index]);
    }
}






/* indexOfSmallest returns the index of the smallest value in a segment
 * of the array provided in 'scores'. The array segment to search is controlled
 * by the parameters 'startingIndex' and 'numItems'.
 */
int indexOfSmallest(const highscore scores[], int startingIndex, int numItems){
    int targetIndex = startingIndex;

    for (int count = startingIndex + 1; count < numItems; count++){
        if (scores[count].score < scores[targetIndex].score){
            targetIndex = count;
        }
    }

    return targetIndex;
}






/* displayData walks through the arrays starting at the end and prints the
 * values of both arrays.
 */
 void displayData(const highscore scores[], int size){
     cout << "Top Scorers:" << endl;
     for (int index = size -1 ;index > -1 ; index --){
        cout << scores[index].name << ": " << scores[index].score << endl;
     }
     cout << endl;
 }
/* Commented runs:
mdavis@jarvis:~/school/cis278$ ./a8_1
How many scores will you enter?: 6
Enter the name for score #1: Chris
Enter the score for score #1: 1994
Enter the name for score #2: Jena
Enter the score for score #2: 1974
Enter the name for score #3: Jon
Enter the score for score #3: 2001
Enter the name for score #4: Mark
Enter the score for score #4: 1972
Enter the name for score #5: Matt
Enter the score for score #5: 1998
Enter the name for score #6: Ncik
Enter the score for score #6: 2006

Top Scorers:
Ncik: 2006
Jon: 2001
Matt: 1998
Chris: 1994
Jena: 1974
Mark: 1972

mdavis@jarvis:~/school/cis278$

*/
