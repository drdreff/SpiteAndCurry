// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// RandomArray.java
// Program that generates 100 random numbers and performs some analysis
// Assignment #6
// Sat Jul 22 20:49:53 PDT 2017
import java.security.SecureRandom; // to allow for random numbers

public class RandomArray{
  public static void main( String[] args ) {

    int numbers[] = new int[100]; // to hold the random nums
    int analysis[] = new int[101]; // for dupe and skip analysis
    int index = 0; // reusable index
    int numCounter =0; // for tracking line spacing
    SecureRandom random = new SecureRandom(); // to make the randoms
    byte[] values = new byte[16]; // 128bit seed should do
    random.nextBytes(values); // seeded and on our way

    // for loop to generate randoms and populate numbers[]
    for (index = 0; index < 100 ; index ++ ){
      numbers[index] = random.nextInt(100)+1;
    }
    // sort the array using provided bubbleSort
    bubbleSort(numbers);

    System.out.print("Sorted Array");
    // display the random numbers 10 per line
    for (index = 0; index < 100 ; index ++ ){
      // start a new line on mod 10
      if (index % 10 == 0){
        System.out.println();
      }
      System.out.printf("%3d ",numbers[index]);
    }
    System.out.printf("%n%nDuplicate  Count%n");
    //Determine how many duplicates there are
    for (int number : numbers ){
      analysis[number] ++;
    }
    // and display each duplicated number and the count
    for (index = 1; index < 101 ; index ++ ){
      if (analysis[index] > 1 ){
        System.out.printf("%5d        %d%n",index,analysis[index]);
      }
    }
    // Determine all numbers from 1-100 that are missing from the array
    System.out.printf("%nMissing Numbers%n");
    // reuse the analysis array, it also stores what's missing
    for (index = 1; index < 101 ; index ++ ){
      if (analysis[index] == 0){
        System.out.printf("%3d  ",index);
        // rows of 5 per line
        numCounter ++ ; //
        if (numCounter % 5 == 0){
          System.out.println();
        }
      }
    }
    System.out.printf( "%n%nProgrammed by Mark Davis%n" );
  } //end main

  // sort elements of array with bubble sort
  public static void bubbleSort( int [] data ) {
     // loop for data.length - 1 passes
     for ( int pass = 1; pass < data.length; pass++ ) {
       // loop over elements in array
       for ( int index = 0; index < data.length - 1; index++ ) {
         // swap adjacent elements if first is greater than second
         if ( data[ index ] > data[ index + 1 ] ) {
            int temporary = data[ index ]; // store in temporary
            data[ index ] = data[ index + 1 ]; // replace first
            data[ index + 1 ] = temporary; // replace second
          }
        } // end inner for
     } // end outer for
  } // end method bubbleSort

} // end class
