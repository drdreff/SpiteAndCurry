/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 279
 * Assignment #1
 * Sun Feb 11 12:37:48 PST 2018
 * Goal: a program that finds shapes of high bits within a bitmap array
 */

#include <iostream>
#include "make2dArray.h"
#include "arrayQueue.h"
#include "position.h"

using namespace std;

// global variables
int **pixel;
int size;      // number of rows and columns in the image

void outputImage();
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

void labelComponents()
{// Label the components.
    int shapeNum = 2;       // first shape will be #2
    // max queue length is the length of a row +1 (doesn't matter here)
    arrayQueue<position> q; // queue of pixels to color
    position here;          // current pixel
    position neighbor;      // a neighbor to visit

    for (int i = 1; i <= size; i++){
        for (int j = 1; j <= size; j++){
            if (pixel[i][j] == 1 ){
                // We're lit, add other places to light to the queue
                here.row = i;
                here.col = j;
                // wastefully pushing here onto the queue
                q.push(here);

                do {
                    here = q.front();         // get next position
                    q.pop();
                    pixel[here.row][here.col] = shapeNum;
                    // these ifs could use the offset loop...
                    if (pixel[here.row][here.col+1] == 1){ // right
                        neighbor.row = here.row;
                        neighbor.col = here.col+1;
                        pixel[neighbor.row][neighbor.col] = shapeNum;
                        q.push(neighbor);
                    }
                    if (pixel[here.row+1][here.col] == 1){ // down
                        neighbor.row = here.row+1;
                        neighbor.col = here.col;
                        pixel[neighbor.row][neighbor.col] = shapeNum;
                        q.push(neighbor);
                    }
                    if (pixel[here.row][here.col-1] == 1){ // left
                        neighbor.row = here.row;
                        neighbor.col = here.col-1;
                        pixel[neighbor.row][neighbor.col] = shapeNum;
                        q.push(neighbor);
                    }
                    if (pixel[here.row-1][here.col] == 1){ // up
                        neighbor.row = here.row-1;
                        neighbor.col = here.col;
                        pixel[neighbor.row][neighbor.col] = shapeNum;
                        q.push(neighbor);
                    }
                    outputImage();
                    cout << "length: " << q.size()<< endl;
                } while (! q.empty()); // items in queue
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
