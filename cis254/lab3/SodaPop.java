// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// SodaPop.java
// Test program to execize GradeBook class
// Lab #3
// Sat Jul  1 16:16:25 PDT 2017
public class SodaPop {

    public static void main( String[] args ) {
      int counter = 1;
      // use a while loop to print numbers 1-100
      while ( counter <= 100 ){
        if ( counter % 3 == 0 && counter % 5 == 0 ){
          // if the number is divisible by 3 AND 5 print *SP*.
          System.out.printf( "%5s", "*SP*" );
        } else if ( counter % 3 == 0 ) {
          // if the number is divisible by 3 print Soda instead of the number
          System.out.printf( "%5s", "Soda" );
        } else if ( counter % 5 == 0 ) {
          // if the number is divisible by 5 print Pop instead of the number.
          System.out.printf( "%5s", "Pop" );
        } else {
          System.out.printf( "%5d", counter );
        }
        // if the number is divisible by 10 print a newline
        if ( counter % 10 == 0 ){
          System.out.println();
        }
        // increment the counter
        counter++;
      } // end while

      System.out.printf( "%nProgrammed by Mark Davis%n" );
    } // end main
} // end SodaPop
