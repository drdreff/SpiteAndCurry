public class ParkingMeter{

  private int timeLeft =0;
  private int maxTime;

  public ParkingMeter(int max){
    this.maxTime = max;
  }

  public boolean add (int coins){
    boolean update = (coins == 25 && this.timeLeft + 30 <= this.maxTime);
    this.timeLeft += update ? 30 : 0;
    return update;
  }

  public void tick(){
    this.timeLeft -= (this.timeLeft > 0 ) ? 1 : 0 ;
  }
  public boolean isExpired(){
    return (this.timeLeft == 0 );
  }
}
