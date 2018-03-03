/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 279
 * heap exploration
 *
 * Goal: explore building our own heap
 */

# include <iostream.h>
# include <PriorityQueue>
# include <vector>
# include "event.h"

class randomInteger {
    public:
    unsigned int operator ( ) (unsigned int);
    } randomizer;

    unsigned int randomInteger::operator ( ) (unsigned int max)
{
// rand return random integer
// convert to unsigned to make positive
// take remainder to put in range
unsigned int rval = rand( );
return rval % max;
}
unsigned int randBetween(int low, int high) {
return low + randomizer(high - low);
}
class SoftwareGurusBar {
 public:
 // try with 50 chairs, then try with 40, 60, ...
 // in order to find out “optimal” profit prospects
 SoftwareGurusBar( )
 : freeChairs(50), profit(0.0) { }
 bool canSeat (unsigned int numberOfPeople); // slide 12
 void order(unsigned int beerType); // slide 13
 void leave(unsigned int numberOfPeople); // slide 13
 unsigned int freeChairs;
 double profit;
};
SoftwareGurusBar theBar;
SimulationFramework theSimulation;

bool SoftwareGurusBar::canSeat (unsigned int numberOfPeople)
{
// if sufficient room, then seat customers
cout << "Time: " << theSimulation.currentTime;
cout << " Group of " << numberOfPeople << " customers arrives";
if (numberOfPeople < freeChairs) {
 cout << " Group is seated" << endl;
 freeChairs -= numberOfPeople;
 return true;
 }
else {
 cout << " No room, group leaves" << endl;
 return false;
 }
}
void SoftwareGurusBar::order (unsigned int beerType)
{
// serve beer
cout << "Time: " << theSimulation.currentTime;
cout << " serviced order for " << beerType << endl;
// update profit based on this beerType
// add your code here ...
}
void SoftwareGurusBar::leave (unsigned int numberOfPeople)
{
// people leave, free up chairs
cout << "Time: " << theSimulation.currentTime;
cout << " group of size " << numberOfPeople << " leaves" << endl;
freeChairs += numberOfPeople;
}
void main( ) {
// load priority queue with initial Arrive Events then run simulation
unsigned int t = 0;
 // load 4 hours (240 minutes) of Arrive Events
while (t < 240) {
 // new group every 2-5 minutes
 t += randBetween(2,5);
 // group size ranges from 1 to 5
 theSimulation.scheduleEvent(new ArriveEvent(t, randBetween(1,5)));
 }
 // then run simulation and print profits
 theSimulation.run( );
 cout << "Total profits " << theBar.profit << endl;
}
