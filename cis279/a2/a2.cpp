/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 279
 * Assignment #2 The Sofwatre Gurus Bar
 *
 * Goal: explore building our own heap and using it as a PriorityQueue
 */

# include <iostream>
// # include "PriorityQueue.h"
// # include <vector>
# include "event.h"
# include "randomInteger.h"
# include "SoftwareGurusBar.h"

using namespace std;

SoftwareGurusBar theBar;
SimulationFramework theSimulation;

int main( ) {
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
