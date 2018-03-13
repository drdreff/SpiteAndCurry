

class randomInteger {
    public:
        unsigned int operator ( ) (unsigned int);
    } randomizer;

    unsigned int randomInteger::operator ( ) (unsigned int max){
        // rand return random integer
        // convert to unsigned to make positive
        // take remainder to put in range
        unsigned int rval = rand( );
        return rval % max;
    }

    unsigned int randBetween(int low, int high) {
        return low + randomizer(high - low);
}
