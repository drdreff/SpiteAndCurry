// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// BicycleTest.java
// Program to test Bicycle.java
// Lab #2
// Date Sun Jun 25 15:34:55 PDT 2017
/**
 * BicycleTest.java
 *
 * PLACE CODE IMMEDIATELY AFTER COMMENT
 *
 *
 */

public class BicycleTest {

    public static void main( String[] args )  {

      // Create 1 Bicycle reference variable. For example: myBike
      Bicycle myBike;

      // Create 1 String reference variable for the owner's name
      String ownerName =""; // initialize this to null is good practice

      // Create 1 integer variable for license number
      int licenseNumber; // don't need to initialize ints

      // Assign your full name and a license number to the String and
      // integer variables
      ownerName = "Mark Davis";
      licenseNumber = 24601;

      // Create a Bicycle object with the Bicycle class constructor
      // Use the variables you created as arguments to the constructor
      myBike = new Bicycle(ownerName,licenseNumber);

      // Output the owner's name and license number in printf statements
      // using the object reference and the get methods.
      // For example: bike.getOwnerName()
      System.out.printf("Owner name: %s%n", myBike.getOwnerName());
      System.out.printf("License Number: %d%n", myBike.getLicenseNumber());

      // Change the owner's name to Kenny McCormick using setOwnerName
      myBike.setOwnerName("Kenny McCormick");

      // Output the owner's name and license number in printf statements
      // using the Bicycle object reference variable and the get methods.
      System.out.printf("Owner name: %s%n", myBike.getOwnerName());
      System.out.printf("License Number: %d%n", myBike.getLicenseNumber());

    }
}
