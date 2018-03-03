// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// LetterGrades.java
// Program that converts percentages into letter grades
// Lab #5
// Sun Jul 16 13:12:46 PDT 2017
import java.util.Scanner; // to get values from the user

public class LetterGrades{
  public static String findLetterGrade(double grade){
    String gradeLetter = "";

    // binary search is most effecient for bell curve like data
    if (grade >= 80){
      if (grade >= 90){
        if (grade >= 93){
          gradeLetter = "A"; // 93-100 A
        } else {
          gradeLetter = "A-"; // 90-92 A-
        }
      } else if (grade < 87){
        if (grade >= 83){
          gradeLetter = "B"; // 83-86 B
        } else {
          gradeLetter = "B-"; // 80-82 B-
        }
      } else {
        gradeLetter = "B+"; // 87-89 B+
      }
    } else if (grade < 77){
      if (grade >= 67){
        if (grade >= 70){
          gradeLetter = "C"; // 70-76 C
        } else {
          gradeLetter = "D+"; // 67-69 D+
        }
      } else if (grade  < 63){
        if (grade >=60){
          gradeLetter = "D-"; // 60-62 D-
        } else {
          gradeLetter = "F"; // 0-59 F
        }
      } else {
        gradeLetter = "D"; // 63-66 D
      }
    } else {
      gradeLetter = "C+"; // 77-79 C+
    }
    return gradeLetter;
  }

  public static void main( String[] args )  {
    double grade = 0; // input strage
    String gradeLetter =""; // for our return value
    Scanner input = new Scanner(System.in); // to get user input

    while (grade != -1 ){ // grade holds our sentinal
      System.out.print("Enter a grade (0-100) or -1 to quit: ");
      grade = input.nextDouble();
      if ( grade >= 0 && grade <= 100 ){
        gradeLetter = findLetterGrade(grade);
        System.out.printf("The letter grade is for %.2f is %s%n%n",grade,gradeLetter);
      // only print the error if we're not quitting
      } else if (grade != -1){
        System.out.println("Input out of range, please try again.");
      }
    } // end while
    System.out.printf( "%nProgrammed by Mark Davis%n" );
  } //end main
} // end class
