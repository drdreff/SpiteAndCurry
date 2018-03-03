/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b Creature HEADER
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
*/
#ifndef CREATURE_H
#define CREATURE_H

namespace cs_creature {
    class Creature {
        public:
            Creature();             // initialize to Human, 10 strength, 10 hitpoints
            Creature(int newStrength, int newHitpoints);
            virtual int getDamage() const;  // returns the amount of damage this Creature
                                    // inflicts in one round of combat
            virtual std::string getSpecies() const = 0;    // returns the type of the species
            int getStrength() const;
            int getHitpoints() const; // also include appropriate accessors and mutators
            void setStrength(const int newStrength);
            void setHitpoints(const int newHitpoints); // also include appropriate accessors and mutators
        private:
            int strength;           // how much damage this Creature inflicts
            int hitpoints;          // how much damage this Creature can sustain
    };
}
#endif
