/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #16.3
 * Sun Dec  3 18:08:47 PST 2017
 * Goal: Write a recursive function that sorts an array of integers from
 * smallest to largest. It uses a selection sort structure to accomplish
 * this task.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// prototypes
void sortInts(int list[], int min, int max);
int indexOfSmallest(const int list[], int startingIndex, int numItems);
void displayData(const int list[], int size);

// constants
const int LENGTH = 10; // number of ints to sort per array
const int COUNT = 10; // number of tests to run


int main(){

    srand(static_cast<unsigned>(time(0))); // seeding random

    int* testInts = new int[LENGTH]; //
    for (int i = 0; i != COUNT; ++ i){
        for (int j = 0; j != LENGTH; ++ j){
            testInts[j] = rand() % 100;
        }
        // print out the unsorted data
        cout << "Unsorted: ";
        displayData(testInts, LENGTH);
        // sort the array
        sortInts(testInts, 0, LENGTH -1);
        // // print out the sorted data
        cout << endl << "Sorted: ";
        displayData(testInts, LENGTH);
        cout << endl << endl ;
    }
    delete [] testInts;
}







/* sortInts will sort the data such that the smallest  value wil be
 * stored in the lowest indexed element of the array.
 */
void sortInts(int list[], int min, int max){
    //cout << list[min] << ":"<< min << endl;
    if (min < max){
        int targetIndex = indexOfSmallest(list, min, max);
        swap(list[targetIndex], list[min]);
        sortInts(list, min +1, max );
    }
}






/* indexOfSmallest returns the index of the smallest value in a segment
 * of the array provided in 'list'. The array segment to search is controlled
 * by the parameters 'startingIndex' and 'numItems'.
 */
int indexOfSmallest(const int list[], int startingIndex, int numItems)
    {
        int targetIndex = startingIndex;

        for (int count = startingIndex; count <= numItems; count++){
            if (list[count] < list[targetIndex]){
                targetIndex = count;
            }
        }

        return targetIndex;
}






/* displayData walks through the arrays starting at the end and prints the
 * values of both arrays.
 */
 void displayData(const int list[], int size){
     for (int index = 0 ; index != size ; ++ index){
        cout << list[index] << " ";
     }
 }


/* Commented runs:
mdavis@jarvis:~/school/cis278/a16$ g++ a16_3.cpp -o a16_3 && ./a16_3
Unsorted: 21 25 57 83 1 20 12 1 17 8
Sorted: 1 1 8 12 17 20 21 25 57 83

Unsorted: 9 61 31 88 7 97 63 57 69 2
Sorted: 2 7 9 31 57 61 63 69 88 97

Unsorted: 29 38 18 66 60 22 50 97 79 47
Sorted: 18 22 29 38 47 50 60 66 79 97

Unsorted: 78 52 24 87 35 26 8 47 27 25
Sorted: 8 24 25 26 27 35 47 52 78 87

Unsorted: 8 88 38 39 28 45 88 91 54 58
Sorted: 8 28 38 39 45 54 58 88 88 91

Unsorted: 45 83 96 15 2 8 37 52 6 68
Sorted: 2 6 8 15 37 45 52 68 83 96

Unsorted: 51 36 21 76 23 8 54 31 8 33
Sorted: 8 8 21 23 31 33 36 51 54 76

Unsorted: 8 68 22 46 7 50 43 96 94 98
Sorted: 7 8 22 43 46 50 68 94 96 98

Unsorted: 6 91 33 54 7 35 62 96 39 20
Sorted: 6 7 20 33 35 39 54 62 91 96

Unsorted: 65 91 56 38 19 80 46 73 63 6
Sorted: 6 19 38 46 56 63 65 73 80 91

mdavis@jarvis:~/school/cis278/a16$
*/
