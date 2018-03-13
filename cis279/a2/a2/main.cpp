/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 279
 * Assignment #2 The Sofwatre Gurus Bar
 *
 * Goal: explore building our own heap and using it as a PriorityQueue
 */

#include <iostream>

#include "bar.h"
#include "event.h"
#include "framework.h"
#include "random.h"

int main(int argc, const char * argv[]) {
    // load priority queue with initial Arrive Events then run simulation
    unsigned int t = 0;

    // load 4 hours (240 minutes) of Arrive Events
    while (t < 240) {
        // new group every 2-5 minutes
        t += randBetween(2,5);
        // group size ranges from 1 to 5
        int groupSize = weightedProbability({20, 20, 20, 20, 20}) + 1;
        theSimulation.scheduleEvent(new ArriveEvent(t, groupSize));
    }

    // then run simulation and print profits
    theSimulation.run();
    std::cout << "Total profits " << theBar.profit << std::endl;
    return 0;
}
