

bool SoftwareGurusBar::canSeat (unsigned int numberOfPeople){
    // if sufficient room, then seat customers
    cout << "Time: " << theSimulation.currentTime;
    cout << " Group of " << numberOfPeople << " customers arrives";
    if (numberOfPeople < freeChairs) {
        cout << " Group is seated" << endl;
        freeChairs -= numberOfPeople;
        return true;
     }
     else {
         cout << " No room, group leaves" << endl;
         return false;
     }
}

void SoftwareGurusBar::order (unsigned int beerType) {
    // serve beer
    cout << "Time: " << theSimulation.currentTime;
    cout << " serviced order for " << beerType << endl;
    // update profit based on this beerType
    profit += menu[beerType];
}

void SoftwareGurusBar::leave (unsigned int numberOfPeople) {
    // people leave, free up chairs
    cout << "Time: " << theSimulation.currentTime;
    cout << " group of size " << numberOfPeople << " leaves" << endl;
    freeChairs += numberOfPeople;
}
