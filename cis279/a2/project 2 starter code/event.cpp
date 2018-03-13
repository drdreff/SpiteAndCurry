//
//  Assignment 2
//
//  event.cpp
//

#include "bar.h"
#include "event.h"
#include "framework.h"
#include "random.h"

void ArriveEvent::processEvent()
{
    if (theBar.canSeat(groupSize))
        // place an order within 2 & 10 minutes
        theSimulation.scheduleEvent (
            new OrderEvent(theSimulation.currentTime + randBetween(2,10), groupSize));
}

void OrderEvent::processEvent()
{
    // each member of the group orders a beer (type 1,2,3)
    for (int i = 0; i < groupSize; i++) {
        int beerType = weightedProbability({15, 25, 60}) + 1;
        theBar.order(beerType);
    }
    int t = theSimulation.currentTime + randBetween(15,35);
    // schedule a LeaveEvent for this group of drinkers
    // all the group leaves together
    // add your code here ...
};

void LeaveEvent::processEvent ()
{
    theBar.leave(groupSize);
}
