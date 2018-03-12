//
//  Assignment 2
//
//  framework.h
//

#ifndef framework_h
#define framework_h

#include <vector>

#include "PriorityQueue.h"
#include "event.h"

class SimulationFramework {
public:
    SimulationFramework () : eventQueue(), currentTime(0) { }
    void scheduleEvent (Event * newEvent)
    {
        // insert newEvent into eventQueue (Priority Queue)
        // Priority Queue is based on MinHeap using newEvent’s time
        eventQueue.insert (newEvent);
    }
    void run();
    unsigned int currentTime;

protected:
    priority_queue <Event *, std::vector<Event *>, eventComparison> eventQueue;
};

extern SimulationFramework theSimulation;

#endif /* framework_h */
