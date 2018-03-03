/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b Cyberdemon HEADER
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
*/
#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include "demon.h"

namespace cs_creature {
    class Cyberdemon: public Demon {
        public:
            Cyberdemon();             // initialize to Demon, 10 strength, 10 hitpoints
            Cyberdemon(int newStrength, int newHitpoints);
            std::string getSpecies() const;    // returns the type of the species
        private:
            // none 
    };
}
#endif
