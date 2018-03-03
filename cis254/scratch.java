/*if (score1 > score2){
  System.out.print("player1 wins");
  player1Wins ++;
  player2Losses ++;
}
else if (score1 < score2){
    System.out.print("player2 wins");
    player1Losses ++;
    player2Wins ++;
}
else if (score1 == score2){
  System.out.print("tie");
  tieCount ++;
}
if(pH <7.0){
  neutral =0;
  base=0;
  acid=1;
} else if(pH >7.0){
  neutral =0;
  base=1;
  acid=0;
}else if(pH == 7.0){
    neutral =1;
  base=0;
  acid=0;
}
class CTest {
 	public static void main(String [] args) {
 		boolean isPremiumCustomer = false;
 		int nbooksPurchased = 0;
 		int freeBooks;
if (isPremiumCustomer == true) {
  if (nbooksPurchased >= 5){
    freeBooks =1;
  } if (nbooksPurchased >=8){
    freeBooks =2;
  }
} else {
  if (nbooksPurchased >= 7){
    freeBooks =1;
  }
  if (nbooksPurchased >= 12){
    freeBooks =2;
  }
}
System.out.print(freeBooks);
	}
 }


public void printLarger( int p1 , int p2){
  System.out.println((p1 > p2) ? p1 : p2)
}

public class ParkingMeter {
  private int timeLeft = 0;

  public static boolean add(int toAdd){
    timeLeft += (toAdd == 25 ) ? 30 :0 ;
    return (toAdd == 25);
  }
  public static void tick(){
    timeLeft -= (timeLeft >0 ) ? 1 :0;
  }
  public static boolean isExpired(){
      return (timeLeft ==0);
  }
}

public class Clock {
  private int hours =0 ;
  private boolean isTicking = false;
  private Integer diff =0;

  public Clock (int cHours, boolean cIsTicking, int cDiff){
      hours = cHours;
      isTicking = cIsTicking;
      diff = cDiff;
  }
}
*/
k=0
do {
  System.out.print('*');
  n--;
}
while (n > 0);
k = 0;
total =0;
while (k <= n){
  total += k * k * k;
  k++;
}


public void dashedLine(int length){
  while (length >0){
    length --;
    System.out.print("-");
  }
  System.out.println();
}

int input =0 ,even =0 ,odd =0, evenCount =0 , oddCount=0;
do {
  input = stdin.nextInt();
  if ( input % 2 == 0  && input >0){
    even += input;
    evenCount++;
  } else if (input > 0 ) {
    odd += input;
    oddCount ++;
  }
} while (input > 0 );
System.out.printf("%d %d %d %d %n",even,odd,evenCount,oddCount);

int input =0 ,lastNum =-1, dupCount =0 ;
do {
  input = stdin.nextInt();
  if ( input == lastNum && input >0 ){
    dupCount ++;
  }
  lastNum = input;
} while (input > 0 );
System.out.printf("%d",dupCount);

double((tickets1 + tickets2 + tickets3) / (class1 + class2 + class3))
(double) distance / speed


int s = 20; int t = s++ + --s;

total =0 ;

for (int k=5;k<175;k+=5){
//    if(k % 5 == 0){
      System.out.printf("%d ",k);
//    }
}

for (i = 1; i <=n ; i ++ ){
  for(j=1; j<=i; j++){
      System.out.print("*");
    }
    System.out.println();
}


for(i=11;i<21;i++)

for (i=lo;i <=hi; i++ ){
  result = lo + hi;
}
k =0;
total =0;
do {
  System.out.print("*")
  k++;
} while (k < 50 );



k =0;
total =0;
do {
  k++;
  total += k * k *k;
} while (k < n );

String label ="";
switch (age) {
  case 2:
   label ="toddler";
      break;
  case 3:
  case 4:
  case 5:
    label ="early childhood";
      break;
  case 6:
  case 7:
   label ="young reader";
      break;
  case 8:
  case 9:
  case 10:
   label = "elementary";
      break;
  case 11:
  case 12:
    label ="middle";
      break;
  case 13,
    label ="impossible";
      break;
  case 14:
  case 15:
  case 16:
   label ="high school";
      break;
  case 17:
  case 18:
    label ="scholar";
      break;
  default:
      label = "ineligible";
      break;
}
System.out.print(label);



String label ="";
switch (status) {
  case 200:
    label ="OK (fulfilled)";
    break;
  case 403:
    label ="forbidden";
    break;
  case 404:
    label ="not found";
    break;
  case 500:
    label ="server error";
    break;
  default:
      label = "ineligible";
      break;
}
System.out.print(label);

String label ="";
response = stdin.nextInt();
switch (response) {
  case 1:
  case 2:
    yesCount ++;
    label ="YES WAS RECORDED";
    break;
  case 3:
  case 4:
    noCount ++;
    label ="NO WAS RECORDED";
    break;
  default:
      label = "INVALID";
      break;
}
System.out.print(label);

n=0;
do {
  n = stdin.nextInt();
  if (n > 1 && n <10){
    break;
  }
} while(true);
