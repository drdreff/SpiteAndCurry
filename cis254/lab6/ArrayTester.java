// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// ArrayTester.java
// Program that reads in 10 integers, prints them and highlights min and max
// lab #6
// Sat Jul 22 19:56:09 PDT 2017
import java.util.Scanner; // to get values from the user

public class ArrayTester {
  public static void main( String[] args )  {
    int numbers[] = new int[10]; // to hold the input
    Scanner input = new Scanner(System.in); // to get user input
    int min =0;  // to hold smallest input
    int max =0;  // to hold largest input
    int index=0; // reusable index for array walking

    System.out.println("Enter 10 integers");
    // fill the array
    for (index=1 ; index <=10 ; index++){
      System.out.printf("Number %d: ",index);
      numbers[index -1 ] = input.nextInt();
    }
    // walk through again using enhanced for to get min and max
    for (int number : numbers ){
      min = number < min ? number : min;
      max = number > max ? number : max;
    }
    // headings
    System.out.printf( "%nIndex     Number%n" );
    System.out.println( "-----------------" );

    // walk through once more to output the input
    for (index=0 ; index < 10 ; index++ ) {
      System.out.printf( "%2d %12d%n",index,numbers[index] );
    }
    System.out.printf( "%nSmallest number: %d%n" ,min);
    System.out.printf( "Largest number: %d%n" ,max);

    System.out.printf( "%nProgrammed by Mark Davis%n" );
  } //end main
} // end class
