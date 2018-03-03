/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b Balrog IMPLEMENTATION
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
 */

#include <iostream>
#include <string>
#include <cstdlib>

#include "balrog.h"
using namespace std;

namespace cs_creature {

    static const string SPECIES ="Balrog";

    Balrog::Balrog(){
        // nothing to see here
    }





    Balrog::Balrog(const int newStrength, const int newHitpoints)

    : Demon(newStrength, newHitpoints)
    {
        // nothing to see here
    }






    string Balrog::getSpecies() const {
        return SPECIES;
    }







    int Balrog::getDamage() const {
        // cout << "The " << this->getSpecies();
        int damage = Demon::getDamage();
        int damage2 = (rand() % this->getStrength()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;

        return damage;
    }
}
