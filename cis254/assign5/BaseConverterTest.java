// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// BaseConverterTest.java
// Program that tests the BaseConverter class
// Assignment #5
// Mon Jul 17 20:31:42 PDT 2017
import java.util.Scanner; // to get values from the user

public class BaseConverterTest{
  public static void main( String[] args )  {
    long number = 0; // User input and loop control
    String convertedString =""; // for our return value
    Scanner input = new Scanner(System.in); // to get user input

    // "The loop must keep executing until the user enters a negative number."
    while (number >=0){
      System.out.print("Enter a non-negative number to convert to binary and hexadecimal (-1 to quit): ");
      number = input.nextLong();

      if (number >=0 ){
        // display the input decimal
        System.out.printf("%nDecimal: %d%n",number);
        // binary
        convertedString = BaseConverter.convertToBinary(number);
        System.out.printf("%nBinary: %s%n",convertedString);
        // hex
        convertedString = BaseConverter.convertToHexadecimal(number);
        System.out.printf("%nHexadecimal: %s%n%n",convertedString);
      }
    } // end while
    System.out.printf( "%nProgrammed by Mark Davis%n" );
  } //end main
} // end class
