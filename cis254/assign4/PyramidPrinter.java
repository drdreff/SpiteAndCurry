// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// PyramidPrinter.java
// Program that prints a power of 2 pyramid.
// Assignment #4
// Tue Jul 11 20:23:17 PDT 2017

class  PyramidPrinter {
  public static void main(String [] args) {

    // rows
    for (int row = 1 ; row <= 8 ; row++ ) {
      // print an offset
      //String spacer = new String(new char[32]).replace('\0', ' ');
      //System.out.print(spacer);
      for (int spacer = 8 - row ; spacer >0 ; spacer-- ){
        System.out.print("    ");
      }
      // count up
      for (double counter = 0 ; counter < row ; counter++ ) {
        System.out.printf("%4.0f", 1 * Math.pow(2, counter) );
      }
      // count down
      for ( double decounter = row - 2 ; decounter >=0 ; decounter-- ) {
        System.out.printf("%4.0f", 1 * Math.pow(2, decounter) );
      }
      // cariage return after each row
      System.out.println();
    }
    System.out.printf( "%nProgrammed by Mark Davis%n" );
  } // end main
} // end PyramidPrinter
