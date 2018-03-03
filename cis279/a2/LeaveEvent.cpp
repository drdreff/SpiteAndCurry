class LeaveEvent : public Event {
    public:
        LeaveEvent (unsigned int time, unsigned int gs)
        : Event(time), groupSize(gs) { }
        virtual void processEvent ( );
    protected:
        unsigned int groupSize;
};

void leaveEvent::processEvent ( ){
    theBar.leave(groupSize);
}
