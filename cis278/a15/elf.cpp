/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b Elf IMPLEMENTATION
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
 */

#include <iostream>
#include <string>
#include <stdlib.h>

#include "elf.h"
using namespace std;

namespace cs_creature {

    static const string SPECIES ="Elf";

    Elf::Elf(){
        // nothing to see here
    }





    Elf::Elf(const int newStrength, const int newHitpoints)

    : Creature(newStrength, newHitpoints)
    {
        // nothing to see here
    }






    string Elf::getSpecies() const {
        return SPECIES;
    }







    int Elf::getDamage() const {
        int damage = Creature::getDamage();
        // Elves inflict double magical damage with a 50% chance
        // cout << "The " << this->getSpecies() << " attacks for "
        //     << damage << " points!" << endl;
        if ((rand() % 2) == 0) {
            cout << "Magical attack inflicts " << damage
             << " additional damage points!" << endl;
            damage *= 2;
        }
        return damage;
    }
}
