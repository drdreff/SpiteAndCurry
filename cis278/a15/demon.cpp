/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b Demon IMPLEMENTATION
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
 */

#include <iostream>
#include <string>
#include <cstdlib>

#include "creature.h"
#include "demon.h"
using namespace std;

namespace cs_creature {

    static const string SPECIES ="Demon";

    Demon::Demon(){
        // nothing to see here
    }





    Demon::Demon(const int newStrength, const int newHitpoints)

    : Creature(newStrength, newHitpoints)
    {
        // nothing to see here
    }






    string Demon::getSpecies() const {
        return SPECIES;
    }







    int Demon::getDamage() const {
        int damage = Creature::getDamage();
        // Demons can inflict damage of 50 with a 25% chance
        // cout << " attacks for " << damage << " points!" << endl;
        if (rand() % 4 == 0) {
            damage = damage + 50;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }
        return damage;
    }
}
