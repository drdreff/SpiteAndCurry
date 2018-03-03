/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b Cyberdemon IMPLEMENTATION
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
 */

#include <iostream>
#include <string>
#include <cstdlib>

#include "cyberdemon.h"
using namespace std;

namespace cs_creature {

    static const string SPECIES ="Cyberdemon";

    Cyberdemon::Cyberdemon(){
        // nothing to see here
    }





    Cyberdemon::Cyberdemon(const int newStrength, const int newHitpoints)

    : Demon(newStrength, newHitpoints)
    {
        // nothing to see here
    }






    string Cyberdemon::getSpecies() const {
        return SPECIES;
    }

}
