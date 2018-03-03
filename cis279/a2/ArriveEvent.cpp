class ArriveEvent : public Event {
    public:
        ArriveEvent (unsigned int time, unsigned int gs) : Event(time), groupSize(gs) { }
        virtual void processEvent ( );
    protected:
        unsigned int groupSize;
};

void ArriveEvent::processEvent( )
{
    if (theBar.canSeat(groupSize)){
    // place an order within 2 & 10 minutes
        theSimulation.scheduleEvent (
            new OrderEvent(theSimulation.currentTime + randBetween(2,10),groupSize)
        );
    }
}
