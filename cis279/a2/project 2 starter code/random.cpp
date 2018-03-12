//
// Assignment 2
//
//  random.cpp
//

#include <cstdlib>

#include "random.h"

randomInteger randomizer;

unsigned int randomInteger::operator () (unsigned int max)
{
    // rand return random integer
    // convert to unsigned to make positive
    // take remainder to put in range
    unsigned int rval = rand();
    return rval % max;
}

unsigned int randBetween(int low, int high) {
    return low + randomizer(high - low + 1);
}

int weightedProbability(const std::vector<unsigned int>& weights) {
    std::vector<unsigned int> partialSums;
    unsigned int sum = 0;
    for (int i = 0; i < weights.size(); i++) {
        sum += weights[i];
        partialSums.push_back(sum);
    }
    unsigned int value = randBetween(1, sum);
    for (int i = 0; i < partialSums.size(); i++) {
        if (value <= partialSums[i]) {
            return i;
        }
    }
    return -1;
}
