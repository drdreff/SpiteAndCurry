// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// Validation.java
// Validate input and print cubes up to 20
// Lab #4
// Sat Jul  8 17:51:57 PDT 2017
import java.util.Scanner; // to get values from the user

public class Validation {
  public static void main( String args[] ) {
    // user input scanner and destination
    Scanner input = new Scanner(System.in);
    int number =0;

    // welcoming text
    System.out.println("Validation By Mark A. Davis");

    // do{}while(true); loops until we break
    do{
      // prompt the user
      System.out.print("Enter an integer between 1 and 20: ");
      number = input.nextInt(); // System.in loops here until we get a number

      // validate the input, and complete if it's good
      if (number > 0 && number <= 20){
        // print the header
        System.out.println("Number Cube");
        // deterministic loop length, from i to user input
        for (int i =1; i <= number ; i ++){
          // pint the numbers i and i^3 aligned
          System.out.printf("%3d %5d %n",i,i*i*i);
        }
        // done with the work, break out of the loop
        break;
      } else { // invliad user input
        // tell the user they're out of line
        System.out.println("Input out of range, please try again.");
        // continue;
      }
    } while (true);
  }// end main
} // end class
