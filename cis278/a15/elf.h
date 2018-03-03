/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b Elf HEADER
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
*/
#ifndef ELF_H
#define ELF_H
#include "creature.h"

namespace cs_creature {
    class Elf: public Creature {
        public:
            Elf();             // initialize to Elf, 10 strength, 10 hitpoints
            Elf(int newStrength, int newHitpoints);
            int getDamage() const;  // returns the amount of damage this Creature
                                    // inflicts in one round of combat
            std::string getSpecies() const;    // returns the type of the species
            //void setStrength();
            //void setHitPoints(); // also include appropriate accessors and mutators
        private:
            // int strength;           // how much damage this Creature inflicts
            // int hitpoints;          // how much damage this Creature can sustain
    };
}
#endif
