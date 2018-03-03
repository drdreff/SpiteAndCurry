class SimulationFramework {
    public:
        SimulationFramework ( ) : eventQueue( ), currentTime(0) { }
        void scheduleEvent (Event * newEvent){
            // insert newEvent into eventQueue (Priority Queue)
            // Priority Queue is based on MinHeap using newEvent’s time
            eventQueue.insert (newEvent);
        }

        void run( );
        unsigned int currentTime;
    protected:
        priority_queue <vector<Event *>, eventComparison> eventQueue;
};

void simulation::run( )
{
    // execute events until event queue becomes empty
    while (! eventQueue.empty( )) {
        // copy & remove min-priority element (min time) from eventQueue
        Event * nextEvent = eventQueue.peak( );
        eventQueue.deleteMin( );
        // update simulation’s current time
        currentTime = nextEvent->time;
        // process nextEvent
        nextEvent->processEvent( );
        // cleanup nextEvent object
        delete nextEvent;
    }
}

class Event {
    public:
        // constructor requires time of event
        Event (unsigned int t) : time(t) { }
        // time is a public data field
        unsigned int time;
        // execute event by invoking this method
        virtual void processEvent( ) { }
};

class eventComparison {
    public:
        bool operator ( ) (Event * left, Event * right){
            return left->time > right->time;
        }
};
