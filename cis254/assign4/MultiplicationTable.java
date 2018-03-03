// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// MultiplicationTable.colava
// Program that displays a multiplication table.
// Assignment #4
// Mon Jul 10 20:23:01 PDT 2017

class  MultiplicationTable {
  public static void main(String [] args) {
    // Heading
    System.out.println("                  Multiplication Table");
    System.out.println("       1   2   3   4   5   6   7   8   9  10  11  12");
    System.out.println("-----------------------------------------------------");
    // rows
    for (int row = 1 ; row <= 12 ; row++ ) {
      // columns
      System.out.printf("%2d |",row);
      for (int col = 1 ; col <= 12 ; col++ ) {
        System.out.printf("%4d", row * col );
      }
      // cariage return after each row
      System.out.println();
    }
    System.out.printf( "%nProgrammed by Mark Davis%n" );
  } // end main
} // end MultiplicationTable
