/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b Human IMPLEMENTATION
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
 */

#include <iostream>
#include <string>

#include "creature.h"
#include "human.h"
using namespace std;

namespace cs_creature {

    static const string SPECIES ="Human";

    Human::Human(){
        // nothing to see here
    }





    Human::Human(const int newStrength, const int newHitpoints)

    : Creature(newStrength, newHitpoints)
    {
        // nothing to see here
    }






    string Human::getSpecies() const {
        return SPECIES;
    }

}
