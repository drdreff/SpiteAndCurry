import java.util.Scanner; // to get values from the user
import java.security.SecureRandom; // to allow for random numbers


public class CTest {

  public static void main( String args[] ) {
    
    int numbers[][] = new int[10][10];
    SecureRandom random = new SecureRandom(); // to make the randoms
    byte[] values = new byte[16]; // 128bit seed should do
    random.nextBytes(values); // seeded and on our way
    for (int index = 0; index < 100 ; index ++ ){
      numbers[index%10][index/10] = random.nextInt(500)+1;
    }
    for (int row = 0; row <10; row++ ){
      for(int col =0; col <10; col++){
        System.out.printf("%5d", numbers[row][col]); // 2 spaces of padding
      }
      System.out.println();
    }
   }
}
/*

HTML Editor Keyboard Shortcuts



public class CTest {
  public static void main(String[] args) {
String str = "World Wide Web";
System.out.println(str.substring( 11 ) );
System.out.println(str.charAt( 8 ) );
System.out.println(str.substring( 0, 5 ) );
  }
}



public class GasTank {
  private double amount =0;
  private double capacity;

  public GasTank(double cap){
    this.capacity = cap;
  }
  public void addGas(double gas){
    this.amount = (this.amount + gas > this.capacity)? this.capacity : this.amount + gas;
  }
  public void useGas(double gas){
    this.amount = (this.amount < gas) ? 0 : this.amount - gas;
  }
  public boolean isEmpty(){
    return (this.amount < 0.1);
  }
  public boolean isFull(){
    return (this.amount > this.capacity - 0.1);
  }
  public double getGasLevel(){
    return this.amount;
  }
  public double fillUp(){
    double gasNeeded = this.capacity - this.amount ;
    this.amount = this.capacity ;
    return gasNeeded;
  }
}

public class Value {
  private boolean modified = false;
  private int val;

  public Value (int val){
    this.val = val;
  }
  public int getVal(){
    return this.val;
  }
  public void setVal(int val){
    this.modified = true;
    this.val = val;
  }
  public boolean wasModified(){
    return modified;
  }
}
public class Player{
  private String name = "";
  private int score =0;

  public void setName (String name){
    this.name = name;
  }

  public void setScore (int score ){
    this.score = score;
  }
  public String getName (){
    return this.name;
  }
  public int getScore (){
    return this.score;
  }
}

public class ContestResult {
  private String winner ="";
  private String secondPlace ="";
  private String thirdPlace ="";
  public void setWinner(String name){
    this.winner = name;
  }
  public void setSecondPlace(String name){
    this.secondPlace = name;
  }

  public void setThirdPlace(String name){
    this.thirdPlace = name;
  }
  public String getWinner(){
    return this.winner;
  }
  public String getSecondPlace(){
    return this.secondPlace;
  }
  public String getThirdPlace(){
    return this.thirdPlace;
  }

}

public class PlayListEntry {
  private String title ="";
  private String artist ="";
  private int playCount =0;

  public void setTitle(String title){
    this.title = title;
  }
  public void setArtist(String artist){
    this.artist = artist;
  }
  public void setPlayCount(int count){
    this.playcount = count;
  }

  public String getTitle(){
    return this.title;
  }
  public String getArtist(){
    return this.artist;
  }
  public int getPlayCount(){
    return this.playCount;
  }

}
public class WeatherForecast {
  private String skies ="";
  private int high=0;
  private int low =0;

  public void setSkies(String skies){
    this.skies = skies;
  }
  public void setHigh(int high){
    this.high = high;
  }
  public void setLow(int low){
    this.low = low;
  }

  public String getSkies(){
    return this.skies;
  }
  public int getHigh(){
    return this.high;
  }
  public int getLow(){
    return this.low;
  }
}


String name1, name2, name3;
Scanner stdin = new Scanner(System.in);

name1 = stdin.next();
name2 = stdin.next();
name3 = stdin.next();
System.out.printf("%s, %s and %s%n",name1,name2,name3);
System.out.printf("%s, %s and %s%n",name1,name3,name2);
System.out.printf("%s, %s and %s%n",name2,name3,name1);
System.out.printf("%s, %s and %s%n",name2,name1,name3);
System.out.printf("%s, %s and %s%n",name3,name2,name1);
System.out.printf("%s, %s and %s%n",name3,name1,name2);
name = stdin.next();
age =stdin.nextInt();
System.out.printf("The age of %s is %d",name,age);

System.out.printf("i=%d f=%f",i,f);

public String makeSubjectLine(String line){
return "Subject: "+line;
}
public String makeEmailAddress(String user, String domain){
return user+"@"+domain;
}

String nameChunks[] = fullName.split(" ");
if(nameChunks[0].indexOf(",") != -1){
  lastName = nameChunks[0].split(",")[0];
  firstName = nameChunks[1];
} else {
  lastName = nameChunks[1];
  firstName = nameChunks[0];
}
  System.out.println(firstName);
  System.out.println(lastName);

  }
  public String getEmailUserName(String email){
    return email.split("@")[0];
  }
  public String getEmailDomain(String email){
    return email.split("@")[1];
  }
  public String getFirstLine(String email){
    return email.split("\n")[0];
  }
  public String getSecondLine (String email){
    return email.substring(email.indexOf("\n") + 1,
    email.indexOf("\n") + 1 + email.substring(email.indexOf("\n") + 1,
    email.length()).indexOf("\n"));
  }

}
/*
  public static void main(String [] args) {
    String className="foo";
    if (className == args[0] && args.length==1){
      displayHelp();
    } else if (args.length < 4){
      argsError(args.length);
    }
    for (String arg : args){
      System.out.printf("arg: %s%n",arg);
    }
  }
  public static void processArgs(String [] args){
    System.out.println("process args");
  }
  public static void argsError(int numArgs){
    System.out.println("args error");
  }
  public static void displayHelp(){
    System.out.println("help text");
  }

}
/*

    int[] foo[]={10,20,30,40};

    reverse(foo);

    public void reverse (int in[]){
      int hodlr = 0;
      for (int i=0; i<in.length/2; i++){
        hodlr = in[i];
        in[i] = in[in.length-i-1];
        in[in.length-i-1] = hodlr;
      }
    }

mostTickets=0;
for (k=0;k!=parkingTickets.length;k++)
  mostTickets = (parkingTickets[k]>mostTickets)?parkingTickets[k]:mostTickets;
  }

westboundHollandTunnelTraffic = new int[24][7][52][2];
hour:day:week:year:cars
0:0:0:0:
1:


isRectangular = true;
for (int i=1;i!=a2d.length;i++){
  isRectangular = (a2d[0].length == a2d[i].length && isRectangular);
}

nElements =0;
for (int i=0;i!=a2d.length;i++){
  nElements += a2d[i].length;
}

sum =0;
for (int i=0;i!=a2d.length;i++){
  for (int j=0;j!=a2d[i].length;j++){
    sum += a2d[i][j];
  }
}

nNegative=0;
for (int i=0;i!=a2d.length;i++){
  for (int j=0;j!=a2d[i].length;j++){
    nNegative += (a2d[i][j]<0)?1:0;
  }
}

// diags
tictactoe[0][0] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][2] ||
tictactoe[0][2] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][0] ||
//rows
tictactoe[0][0] == tictactoe[0][1] && tictactoe[0][1] == tictactoe[0][2] ||
tictactoe[1][0] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[1][2] ||
tictactoe[2][2] == tictactoe[2][1] && tictactoe[2][1] == tictactoe[2][2] ||
//columns
tictactoe[0][0] == tictactoe[1][0] && tictactoe[1][0] == tictactoe[2][0] ||
tictactoe[0][1] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][1] ||
tictactoe[0][2] == tictactoe[1][2] && tictactoe[1][2] == tictactoe[2][2]


public class Book{

  private String title;
  private String author;
  private String tableOfContents ="";
  private int nextPage=1;

  public Book(String course, String instructor){
    this.title = course;
    this.author = instructor;
  }

  public void addChapter(String title, int pages){
    this.tableOfContents += String.format("%n%s...%d",title,this.nextPage);
    this.nextPage += pages;
  }

public int sumArray (int in[]){
  int ArraySum = 0;
  for (int i = 0; i != in.length ; i++ ){
    ArraySum += in[i];
  }
  return ArraySum;

}
  public boolean isReverse(int ary1[], int ary2[]){
    boolean retVal = true;
    for (int i =0; i != ary1.length ; i ++ ){
      if (retVal){
       retVal = (ary1[i] == ary2[ary2.length -i -1]);
     }
    }
    return retVal;
  }

  public void reverse (int in[]){
    int hodlr = 0;
    for (int i=0; i<=in.length/2; i++){
      hodlr = in[i];
      in[i] = in[in.length-i-1];
      in[in.length-i-1] = hodlr;
    }
  }
  public int getPages(){
    return this.nextPage -1;
  }
  public String getTableOfContents(){
    return this.tableOfContents;
  }

  public String toString(){
    return String.format("%s%n%s",title,author);
  }
}
public static void method1(int number) {

    int value = 0;

    for(int counter = 1; counter <= number; counter++) {
        value += counter;
    }
    System.out.printf("value is %d counter is %d", value, counter);
}

}
/*    Scanner stdin = new Scanner(System.in);

    double areaOfSquare =0;

    areaOfSquare = stdin.nextDouble();
    if (areaOfSquare <0){
      System.out.print("INVALID");
    } else {
      System.out.print(Math.sqrt(areaOfSquare));
    }

    if (b*b -4.0*a*c <0){
      System.out.print("no real solutions" );
      return;
    }
  }
  public static int twice(int param) {
    return param *2;
  }
    public static int add(int param1, int param2) {
    return param1 + param2;
  }
    public static int max(int param1, int param2, int param3) {
    return Math.max(Math.max(param1, param2),param3);
  }
  public static int min(int param1, int param2){
    return (param1 > param2) ? param2 : param1;
  }
  public static double powerTo(double param1, int param2){
    return (param2 < 0 ) ? 0 : Math.pow(param1,param2);
    */
