//
//  Assignment 2
//
//  event.h
//

#ifndef event_h
#define event_h

class Event {
    public:
        // constructor requires time of event
        Event (unsigned int t) : time(t) { }
        // time is a public data field
        unsigned int time;
        // execute event by invoking this method
        virtual void processEvent() { }
};

class eventComparison {
    public:
        bool operator () (Event * left, Event * right)
        {
            return left->time > right->time;
        }
};

class ArriveEvent : public Event {
    public: ArriveEvent (unsigned int time, unsigned int gs)
        : Event(time), groupSize(gs) { }
        virtual void processEvent ();
    protected:
        unsigned int groupSize;
};

class OrderEvent : public Event {
    public: OrderEvent (unsigned int time, unsigned int gs)
        : Event(time), groupSize(gs) { }
        virtual void processEvent ();
    protected:
        unsigned int groupSize;
};

class LeaveEvent : public Event {
    public:
        LeaveEvent (unsigned int time, unsigned int gs)
        : Event(time), groupSize(gs) { }
        virtual void processEvent ();
    protected:
        unsigned int groupSize;
};

#endif /* event_h */
