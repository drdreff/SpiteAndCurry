/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b Balrog HEADER
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
*/
#ifndef BALROG_H
#define BALROG_H
#include "demon.h"

namespace cs_creature {
    class Balrog: public Demon {
        public:
            Balrog();             // initialize to Demon, 10 strength, 10 hitpoints
            Balrog(int newStrength, int newHitpoints);
            int getDamage() const;  // returns the amount of damage this Creature
                                    // inflicts in one round of combat
            std::string getSpecies() const;    // returns the type of the species
        private:
            // none
    };
}
#endif
