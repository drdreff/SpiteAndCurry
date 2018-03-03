public class Counter {
  private int counter;
  private int counterID;
  private static int nCounters = 0;

  public Counter (int param1){
    this.counter = param1;
    nCounters++;
    this.counterID = nCounters;
  }
  public void increment (){
    this.counter += (this.counter < this.limit)? 1 : 0;
  }
  public void decrement (){
    this.counter -= (this.counter > 0) ? 1 : 0 ;
  }
  public int getValue(){
    return this.counter;
  }
  public int getCounterID(){
    return this.counterID;
  }
}
