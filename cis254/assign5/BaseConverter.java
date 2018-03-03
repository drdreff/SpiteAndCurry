// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// BaseConverter.java
// Class that returns numbers in different bases (2,10,16)
// Assignment #5
// Mon Jul 17 20:32:09 PDT 2017

public class BaseConverter{
  private static final char[] hexDigits = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
  };

  public static String convertToBinary( long decimal ) { // base 2
    // bitwise operations would probably be faster, divide by 2 works fine
    String convertedString = "";
    if (decimal < 0){
      convertedString = "";
    } else {
      do {
        // the mod 2 of decimal will always be a 0 or 1
        convertedString = Long.toString(decimal % 2) + convertedString;
        // because we need the quotient and the remainder
        decimal /= 2;
      } while (decimal >0);
    }
    return convertedString;
  }

  public static String convertToHexadecimal( long decimal )  {// base 16
    String convertedString = "";
    if (decimal < 0){
      convertedString = "";
    } else {
      do {
        // the mod 16 of decimal is a handy index to our array
        convertedString = hexDigits[(int)(decimal % 16)] + convertedString;
        // because we need the quotient and the remainder
        decimal /= 16;
      } while (decimal >0);
    }
    return convertedString;
  }
} // end class
