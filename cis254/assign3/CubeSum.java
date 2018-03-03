// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// CubeSum.java
// Program that outputs 3 digit Armstrong numbers
// Assignment #3
// Sat Jul  1 17:21:30 PDT 2017
class CubeSum {
  public static void main(String [] args) {
    // counter to walk from 100 to 999
    int counter = 100;

    // integers to hold the individual digits
    int hundreds =0;
    int tens = 0;
    int ones = 0 ;

    // this will only test values less than 1000
    do {
      // break the number up into the individual digits
      ones = counter % 10;
      tens = (counter % 100 )/10;
      hundreds = counter / 100;

      // Math.pow(foo,3) is inappropriate, so we cube them by hand
      ones *= ones * ones;
      tens *= tens * tens;
      hundreds *= hundreds * hundreds;
      // add them up and compare to the original
      if (hundreds + tens + ones == counter ){
        System.out.printf("%3d%n",counter);
      }
      // increment the counter
      counter++;
    } while (counter < 1000);
    System.out.printf( "%nProgrammed by Mark Davis%n" );
  } // end main
} // end CubeSum
