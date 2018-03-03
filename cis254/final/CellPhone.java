// Mark Davis
// markdavis@my.smccd.edu
// Fri Aug  4 21:15:43 PDT 2017
public class CellPhone {

  private String manufacturer;
  private String model;
  private Double price;

  // constructor initializes instance variables
  public CellPhone ( String manufacturer, String model, double price) {
    this.manufacturer = manufacturer;
    this.model = model;
    // call the setter to use the same validation logic
    setPrice(price);
  } // end constructor

  public void setManufacturer( String manufacturer ){
    this.manufacturer = manufacturer;
  }
  public String getManufacturer(){
    return this.manufacturer;
  }
  public void setModel( String model ){
    this.model = model;
  }
  public String getModel(){
    return this.model;
  }
  public void setPrice( double price ){
    //default values 0.00 for an invalid price
    if (price < 0.0 ){
      price = 0.0;
    }
    this.price = price;
  }
  public double getPrice(){
    return this.price;
  }
  public String toString(){
    String output = String.format("Manufacturer: %s  Model: %s Price: $%.2f",
      this.manufacturer, this.model, this.price);
    return output;
  }
}// end class
