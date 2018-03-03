/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 279
 * Assignment #1
 * Sun Feb 11 12:37:48 PST 2018
 * Goal: a program that finds shapes of high bits within a bitmap array
 */

#include <iostream>
#include "make2dArray.h"

using namespace std;

// global variables
int **pixel;
int size;      // number of rows and columns in the image
int calls;

// functions
void welcome(){
    // I guess that this is where we introduce the user to the program
    cout << "Welcome, this application analyzes a bitmap and returns one "
        << endl << "with the contiguous shapes marked with ascending values."
        << endl;
}

void inputImage(){// Input the image.
   cout << "Enter image size" << endl;
   cin >> size;

   // create and input the pixel array
   make2dArray(pixel, size + 2, size + 2);
   cout << "Enter the pixel array in row-major order" << endl;
   for (int i = 1; i <= size; i++)
      for (int j = 1; j <= size; j++)
          cin >> pixel[i][j];
}

void markShape(int x, int y, int shapeNum){
    // mark the current pixel
    pixel[x][y] = shapeNum;
    calls ++;
    cout << "calls:" << calls << endl;
    // check all 4 directions for more pixels to mark
    if (pixel[x+1][y] == 1) markShape(x+1,y,shapeNum); // right
    if (pixel[x][y+1] == 1) markShape(x,y+1,shapeNum); // down
    if (pixel[x-1][y] == 1) markShape(x-1,y,shapeNum); // left
    if (pixel[x][y-1] == 1) markShape(x,y-1,shapeNum); // up

}

void labelComponents()
{// Label the components.
    int shapeNum = 2; // first shape will be #2

    for (int i = 1; i <= size; i++){
        for (int j = 1; j <= size; j++){
            if (pixel[i][j] == 1 ){
                markShape(i,j,shapeNum);
                ++ shapeNum; // set the next number
            }
        }
    }
}

void outputImage(){// Output labeled image.

   cout << "The labeled image is" << endl;
   for (int i = 1; i <= size; i++)
   {
      for (int j = 1; j <= size; j++)
         cout << pixel[i][j] << "  ";
      cout << endl;
   }
}

int main(){
   welcome();
   inputImage();
   labelComponents();
   outputImage();
}
