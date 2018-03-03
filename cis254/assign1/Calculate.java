// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// Calculate.java
// Demonstrate a number of numerical operations on input integers
// Assignment #1
// Sun Jun 18 14:24:29 PDT 2017
import java.util.Scanner; // to get values from the user

public class Calculate {
  public static void main( String args[] ) {

    /* The program must prompt the user for 2 integers.
    * The program will calculate and print the sum, difference,
    *  product, quotient and remainder of the 2 numbers.
    */

    // variables to hold user input
    int inInt1 =5 , inInt2 =5;
    String result = "";
    // create an instance of the scanner
    Scanner input = new Scanner(System.in);
/*
    // welcoming text
    System.out.println("Calculations By Mark A. Davis");

    System.out.print("Enter first integer: ");
    // should actually validate the user input here, app will bomb on a float
    inInt1 = input.nextInt(); // assign user input into our first var

    System.out.print("Enter second integer: ");
    inInt2 = input.nextInt(); // assign user input into second integer

    System.out.printf("Sum of %d and %d is: %d%n",
      inInt1, inInt2, inInt1 + inInt2); // sum
    System.out.printf("Difference of %d and %d is: %d%n",
      inInt1, inInt2, inInt1 - inInt2); // difference
    System.out.printf("Product of %d and %d is: %d%n",
      inInt1, inInt2, inInt1 * inInt2); // product
    System.out.printf("Quotient of %d and %d is: %d%n",
      inInt1, inInt2,inInt1/inInt2); // quotient
    System.out.printf("Remainder of %d and %d is: %d%n",
      inInt1, inInt2, inInt1 % inInt2); // remainder

    /* The program will also compare the two numbers and tell the user which number
    *  is larger (or state that they are equal).
    */
/*
    // I'm sure there's a more elegant way to do this.
    if (inInt1 - inInt2 > 0 ){
      result = "greater than";
    }
    if (inInt1 - inInt2 < 0 ){
      result = "less than";
    }
    if (inInt1 - inInt2 == 0 ){
      result = "equal to";
    }
    System.out.printf("%d is %s %d%n", inInt1, result, inInt2);
*/
int value1 = 3;

          int value2 = 5;

          int value3 = 7;

      System.out.println( value1 * (value2 + value3) );
      System.out.println( (value1 + value3) / value2 + 1);
      System.out.println( value2 * value1 - value1 * 2);
      System.out.println( value2 % value1 );

  }
}
