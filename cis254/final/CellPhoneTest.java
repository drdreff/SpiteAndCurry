// Mark Davis
// markdavis@my.smccd.edu
// FINAL!!
// Fri Aug  4 21:15:43 PDT 2017


public class CellPhoneTest {
    public static void main( String[] args )  {
      int counter =0;
      // Load the array on creation
      CellPhone[] myCellPhones = new CellPhone[]{
          new CellPhone("Samsung","Galaxy S8",824.99),
          new CellPhone("Apple","iPhone 7 Plus",769.00),
          new CellPhone("Google","Pixel XL",649.00),
          new CellPhone("LG","V20 4G LTE",-499.00),
      };
      for (CellPhone phone : myCellPhones ){
        counter ++;
        System.out.printf("Cell Phone %d\n%s\n\n",counter,phone.toString());
      }
    } // end main
} // end class
