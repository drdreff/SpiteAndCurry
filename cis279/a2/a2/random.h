//
//  Assignment 2
//
//  random.h
//

#ifndef random_h
#define random_h

#include <vector>

class randomInteger {
public:
    unsigned int operator () (unsigned int);
};

unsigned int randBetween(int low, int high);

// Return an index in range [0, size)
int weightedProbability(const std::vector<unsigned int>& weights);

#endif /* random_h */
