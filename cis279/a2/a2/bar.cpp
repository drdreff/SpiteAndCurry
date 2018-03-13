//
//  Assignment 2
//
//  bar.cpp
//

#include <iostream>

#include "bar.h"
#include "framework.h"

SoftwareGurusBar  theBar;

// prices of local/imported/special beer
const double prices[3] = {2.0, 3.0, 4.0};

bool SoftwareGurusBar::canSeat (unsigned int numberOfPeople)
{
    // if sufficient room, then seat customers
    std::cout << "Time: " << theSimulation.currentTime;
    std::cout << " Group of " << numberOfPeople << " customers arrives";
    if (numberOfPeople < freeChairs) {
        std::cout << " Group is seated" << std::endl;
        freeChairs -= numberOfPeople;
        return true;
    } else {
        std::cout << " No room, group leaves" << std::endl;
        return false;
    }
}

void SoftwareGurusBar::order (unsigned int beerType)
{
    // serve beer
    std::cout << "Time: " << theSimulation.currentTime;
    std::cout << " serviced order for " << beerType << std::endl;
    // update profit based on this beerType
    theBar.profit += prices[beerType];
}

void SoftwareGurusBar::leave (unsigned int numberOfPeople)
{
    // people leave, free up chairs
    std::cout << "Time: " << theSimulation.currentTime;
    std::cout << " group of size " << numberOfPeople << " leaves" << std::endl;
    freeChairs += numberOfPeople;
}
