class OrderEvent : public Event {
     public:
         OrderEvent (unsigned int time, unsigned int gs): Event(time), groupSize(gs) { }
         virtual void processEvent ( );
     protected:
         unsigned int groupSize;
};
void orderEvent::processEvent( )
{
 // each member of the group orders a beer (type 1,2,3)
 for (int i = 0; i < groupSize; i++)
 theBar.order(randBetween(1,3));
 int t = theSimulation.currentTime + randBetween(15,35);
 // schedule a LeaveEvent for this group of drinkers
 // all the group leaves together
 // add your code here ...
};
