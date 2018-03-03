/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b Human HEADER
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
*/
#ifndef HUMAN_H
#define HUMAN_H
#include "creature.h"

namespace cs_creature {
    class Human: public Creature {
        public:
            Human();             // initialize to Human, 10 strength, 10 hitpoints
            Human(int newStrength, int newHitpoints);
            std::string getSpecies() const;    // returns the type of the species
        private:
            // none
    };
}
#endif
