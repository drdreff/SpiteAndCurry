// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// SalesCommission.java
// Calculate the payout for sales employees
// Midterm
// Fri Jul  7 20:17:04 PDT 2017
import java.util.Scanner; // to get values from the user

public class SalesCommission {
  public static void main( String args[] ) {

    // variables to hold user input
    double dailySales = 0;
    double allSales =0;
    String employeeName = "";

    // counter and days for loop
    int counter =1;
    int days = 5;

    // business logic globals
    int basePay = 400;
    double commissionRate = .15;

    // Scanner for user input
    Scanner input = new Scanner(System.in);

    // welcoming text wasn't called for in the instructions
    //System.out.println("Midterm By Mark A. Davis");

    System.out.print("Enter salesperson's name: ");
    // should actually validate the user input here, app will bomb on a float
    employeeName = input.nextLine(); // assign user input into our first var

    while (counter <= days){ // 1..5
      System.out.printf("Enter day %d sales: ",counter);
      // get the daily sales figure
      dailySales = input.nextDouble();
      // only add positive amounts

      // instructions say to use an if:
      if (dailySales > 0) {
        allSales += dailySales;
      }
      // allSales += (dailySales > 0) ? dailySales : 0 ; // does the same

      // increment counter
      counter ++;
    }
    // add the sales commission and base pay
    allSales = basePay + (allSales * commissionRate);
    System.out.printf("%n%s earned $%.2f%n",employeeName,allSales);

  }
}
