// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// GradeBookTest.java
// Test program to execize GradeBook class
// Assignment #2
// Sun Jun 25 18:50:31 PDT 2017
import java.util.Scanner; // to get values from the user

public class GradeBookTest {
    public static void main( String[] args )  {

      Scanner input = new Scanner(System.in);

      //The first GradeBook object will be created with data (Strings) entered by the user in the command prompt window (terminal).
      // call the constructor with empty strings, call the setters later
      GradeBook userGradeBook = new GradeBook("","");

      //The second GradeBook object will be created with the data for CIS 254
      GradeBook CIS254GradeBook = new GradeBook(
        "CIS 254 Intro to Object-Oriented Program Design",
        "Melissa Green"
      );

      System.out.println("Programmed by Mark Davis");

      System.out.println("Enter course name:");
      // calling the setter for courseName
      userGradeBook.setCourseName(input.nextLine());
      System.out.println("Enter instructor's name:");
      // call the setter for the instructorName
      userGradeBook.setInstructorName(input.nextLine());

      //Output the information for both GradeBook objects by calling the displayMessage method on each object.
      userGradeBook.displayMessage();
      CIS254GradeBook.displayMessage();

    }// end main
}// end class
