/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b Creature IMPLEMENTATION
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "creature.h"
using namespace std;

namespace cs_creature {

    static const string SPECIES ="Creature";

    Creature::Creature(){
        strength = 10;
        hitpoints = 10;
    }





    Creature::Creature(int newStrength, int newHitpoints){
        strength = newStrength;
        hitpoints = newHitpoints;
    }






    int Creature::getDamage() const {
        int damage;
        // All Creatures inflict damage which is a random number up to their strength
        damage = (rand() % strength) + 1;
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }






    int Creature::getStrength() const {
        return strength;
    }






    int Creature::getHitpoints() const {
        return hitpoints;
    }






    void Creature::setStrength(const int newStrength) {
        strength = newStrength;
    }






    void Creature::setHitpoints(const int newHitpoints) {
        hitpoints = newHitpoints;
    }

}
