// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// CD.java
// Class file that describes a CD object
// Assignment #7
// Wed Aug  2 19:11:47 PDT 2017
import javax.swing.JOptionPane;

public class CDTest {
    public static void main( String[] args )  {
      // Load the array on creation
      CD[] myCDs = new CD[]{
          new CD("Demon Days","Gorillaz",7.00,15),
          new CD("El Camino","The Black Keys",8.99,11),
          new CD("Elephant","The White Stripes",6.99,14),
          new CD("AM","Arctic Monkeys",8.29,12),
          new CD("Random Access Memories","Daft Punk",6.99,13),
          new CD("Get Born","Jet",11.98,13),
      };
      // heading info
      String output = "Programmed by Mark Davis\n\n";
      String out2 = output;
      output += "My CDs\n";
      System.out.print(output);
      System.out.print(out2);
            // sample had 60 * but that's an overlong line
      output += "******************************";
      output += "******************************\n";
      // append the CD data to the output buffer
      for (CD disk : myCDs ){
        output += disk.toString() + "\n";
      }
      //default title and icon
      JOptionPane.showMessageDialog(null,output);
    } // end main
} // end class
/*
// test data
"Demon Days","Gorillaz",7.00,15
"El Camino","The Black Keys",8.99,11
"Elephant","The White Stripes",6.99,14
"AM","Arctic Monkeys",8.29,12
"Random Access Memories","Daft Punk",6.99,13
"Get Born","Jet",11.98,13
"Empty","Price",-100.0,14
"Invalid","Tracks",6.99,999
*/
