// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// CD.java
// Class file that describes a CD object
// Assignment #7
// Wed Aug  2 19:11:47 PDT 2017

public class CD
{

  private String title;
  private String artist;
  private Double price;
  private int numberOfTracks;

  // constructor initializes instance variables
  public CD ( String title, String artist, Double price, int numberOfTracks)
  {
    this.title = title;
    this.artist = artist;
    // call the setter to use the same validation logic
    setPrice(price);
    setNumberOfTracks(numberOfTracks);
  } // end constructor

  public void setTitle( String title  ){
    this.title = title;
  }
  public String getTitle(){
    return this.title;
  }
  public void setArtist( String artist ){
    this.artist = artist;
  }
  public String getArtist(){
    return this.artist;
  }
  public void setPrice( Double price ){
    //default values 0.00 for an invalid price
    if (price < 0.0 ){
      price = 0.0;
    }
    this.price = price;
  }
  public Double getPrice(){
    return this.price;
  }
  public void setNumberOfTracks( int numberOfTracks ){
    // default 1 for invalid number of tracks (redbook max is 99)
    if (numberOfTracks < 1 || numberOfTracks > 99 ){
      numberOfTracks = 1;
    }
    this.numberOfTracks = numberOfTracks;
  }
  public int getNumberOfTracks(){
    return numberOfTracks;
  }
  public String toString(){
    String output = String.format("%s  %s $%.2f %d tracks",this.artist,this.title,this.price, this.numberOfTracks);
    return output;
  }
}// end class
