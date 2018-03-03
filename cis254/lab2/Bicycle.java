// Mark Davis
// markdavis@my.smccd.edu
// CIS 254 ON
// Bicycle.java
// Class being exercized by BycycleTest.java
// Lab #2
// Date Sun Jun 25 15:34:55 PDT 2017
/*
    File: Bicycle.java
*/

public class Bicycle {

    // Instance field
    private String ownerName;
    private int licenseNumber;

    // Constructor
    public Bicycle( String name, int license ) {
    	ownerName = name;
    	licenseNumber = license;
    }

    // Returns the name of this bicycle's owner
    public String getOwnerName() {

        return ownerName;
    }

    // Assigns the name of this bicycle's owner
    public void setOwnerName( String name ) {

        ownerName = name;
    }

    // Returns the license number of this bicycle
    public int getLicenseNumber() {

        return licenseNumber;
    }

    // Assigns the license number of this bicycle
    public void setLicenseNumber( int license ) {

        licenseNumber = license;
    }

 }
