// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// Reverser.java
// Program that reads in a series of words and redisplys them reversed
// lab #7
// Mon Jul 31 21:04:04 PDT 2017

import java.util.Scanner; // to get values from the user

public class Reverser {
  public static void main( String[] args )  {

    final String ESCAPE ="QUIT"; // user escape sequence
    Scanner input = new Scanner(System.in); // to get user input
    String userString = ""; // to store user input
    boolean flag = true; // loop control

    while (flag){
      String userPunct = ""; // to store punctuation
      System.out.println("Enter a sentence:");
      userString = input.nextLine(); // get the string to manipulate
      userString = userString.trim(); // nuke newline

      if (!userString.toUpperCase().equals(ESCAPE)){
        // check for punctuation at the end
        if (userString.matches(".*\\p{P}$")){
          userPunct = userString.substring(
            userString.length() - 1, userString.length()); // store punctuation
          userString = userString.substring(0,userString.length()-1);
        }
        String[] userWords = userString.split("\\s+"); // split string into an array
        // splice the punctuation on to the last word
        userWords[0] += userPunct;
        System.out.println("Reverse sentence:");
        for (int index = userWords.length-1; index >=0; index-- ){
          System.out.printf("%s ",userWords[index]);
        }
        System.out.println();
      } else { // user entered 'quit'
        flag = false;
      }
    }
    System.out.printf( "%nProgrammed by Mark Davis%n" );
  }// end main
}// end class
