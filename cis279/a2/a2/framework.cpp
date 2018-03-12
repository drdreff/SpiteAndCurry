//
//  Assignment 2
//
//  framework.cpp
//

#include "framework.h"

SimulationFramework  theSimulation;

void SimulationFramework::run()
{
    // execute events until event queue becomes empty
    while (! eventQueue.empty()) {
        // copy & remove min-priority element (min time) from eventQueue
        Event * nextEvent = eventQueue.peak();
        eventQueue.deleteMin();
        // update simulation’s current time
        currentTime = nextEvent->time;
        // process nextEvent
        nextEvent->processEvent(); // what do you see here???
                                   // Polymorphism (dynamic dispatch because of late binding)
                                   // this is why processEvent() is virtual

        // cleanup nextEvent object
        delete nextEvent;
    }
}
