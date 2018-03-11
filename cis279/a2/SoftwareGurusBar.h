
class SoftwareGurusBar {
    public:
        // try with 50 chairs, then try with 40, 60, ...
        // in order to find out “optimal” profit prospects
        SoftwareGurusBar( ) : freeChairs(50), profit(0.0), menu[2,3,4] { }
        bool canSeat (unsigned int numberOfPeople); // slide 12
        void order(unsigned int beerType); // slide 13
        void leave(unsigned int numberOfPeople); // slide 13
        unsigned int freeChairs;
        double profit;
        int menu [];
};
