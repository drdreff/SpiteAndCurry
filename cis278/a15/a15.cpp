/* Mark Davis
 * markdavis@my.smccd.edu
 * CIS 278
 * Assignment #15b CLIENT
 * Sat Nov 25 15:22:41 PST 2017
 * Goal:  Define syntactically correct classes that use inheritance in
 * accordance with good programming practice. Implement constructors and
 * initialization lists in the context of inheritance. Implement polymorphism,
 * virtual functions, abstract base classes, and pure virtual functions.
 */

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "human.h"
#include "elf.h"
#include "cyberdemon.h"
#include "balrog.h"

using namespace std;
using namespace cs_creature;

void battleArena(Creature &Creature1, Creature& Creature2);

int main() {
    srand(time(0));

    Human h1;
    Elf e1;
    Cyberdemon c1;
    Balrog b1;

    Human h(20, 30);
    Elf e(40, 50);
    Cyberdemon c(60, 70);
    Balrog b(80, 90);


    cout << "default " << h1.getSpecies() << " strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
    cout << "default Elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
    cout << "default Cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
    cout << "default Balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
    cout << "non-default Human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
    cout << "non-default Elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
    cout << "non-default Cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
    cout << "non-default Balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;
    cout << endl << endl;

    cout << "Examples of " << h.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
        int damage = h.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << e.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
        int damage = e.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << c.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
        int damage = c.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << b.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
        int damage = b.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;

    h.setHitpoints(30);
    e.setHitpoints(50);
    battleArena(h,e);

    h.setHitpoints(30);
    c.setHitpoints(70);
    battleArena(h,c);

    h.setHitpoints(30);
    b.setHitpoints(90);
    battleArena(h,b);

    e.setHitpoints(50);
    b.setHitpoints(90);
    battleArena(e,b);

    e.setHitpoints(50);
    c.setHitpoints(70);
    battleArena(e,c);

    c.setHitpoints(70);
    b.setHitpoints(90);
    battleArena(c,b);

    // try to induce a tie
    c.setHitpoints(10);
    b.setHitpoints(10);
    battleArena(c,b);

    c.setHitpoints(10);
    b.setHitpoints(10);
    battleArena(c,b);

    c.setHitpoints(10);
    b.setHitpoints(10);
    battleArena(c,b);

}






void battleArena(Creature &Creature1, Creature& Creature2){
    cout << "Let the " << Creature1.getSpecies() << " vs. " <<
        Creature2.getSpecies() << " Battle Begin!" << endl;
    do {
        cout << Creature1.getSpecies() << " HP:" << Creature1.getHitpoints() <<
        " " << Creature2.getSpecies() << " HP: "<< Creature2.getHitpoints() << endl;
        Creature2.setHitpoints(Creature2.getHitpoints() - Creature1.getDamage());
        Creature1.setHitpoints(Creature1.getHitpoints() - Creature2.getDamage());
    } while (Creature1.getHitpoints() >0 && Creature2.getHitpoints() >0);

    if (Creature1.getHitpoints() <= 0 && Creature2.getHitpoints() <=0){
        cout << "It's a tie!" << endl;
    } else if (Creature1.getHitpoints() > Creature1.getHitpoints()){
        cout << Creature1.getSpecies() << " wins with HP:" << Creature1.getHitpoints() <<
        " vs " << Creature2.getSpecies() << " HP: "<< Creature2.getHitpoints() << endl;
    } else {
        cout << Creature2.getSpecies() << " wins with HP:" << Creature2.getHitpoints() <<
        " vs " << Creature1.getSpecies() << " HP: "<< Creature1.getHitpoints() << endl;
    }
    cout << endl;
}
/* Sample run:
mdavis@jarvis:~/school/cis278/a15$ g++ elf.cpp human.cpp creature.cpp cyberdemon.cpp demon.cpp balrog.cpp a15.cpp -o a15 && ./a15
default Human strength/hitpoints: 10/10
default Elf strength/hitpoints: 10/10
default Cyberdemon strength/hitpoints: 10/10
default Balrog strength/hitpoints: 10/10
non-default Human strength/hitpoints: 20/30
non-default Elf strength/hitpoints: 40/50
non-default Cyberdemon strength/hitpoints: 60/70
non-default Balrog strength/hitpoints: 80/90


Examples of Human damage:
The Human attacks for 4 points!
 Total damage = 4

The Human attacks for 11 points!
 Total damage = 11

The Human attacks for 15 points!
 Total damage = 15

The Human attacks for 1 points!
 Total damage = 1

The Human attacks for 19 points!
 Total damage = 19

The Human attacks for 11 points!
 Total damage = 11

The Human attacks for 19 points!
 Total damage = 19

The Human attacks for 4 points!
 Total damage = 4

The Human attacks for 12 points!
 Total damage = 12

The Human attacks for 10 points!
 Total damage = 10


Examples of Elf damage:
The Elf attacks for 20 points!
Magical attack inflicts 20 additional damage points!
 Total damage = 40

The Elf attacks for 10 points!
 Total damage = 10

The Elf attacks for 35 points!
Magical attack inflicts 35 additional damage points!
 Total damage = 70

The Elf attacks for 7 points!
 Total damage = 7

The Elf attacks for 12 points!
 Total damage = 12

The Elf attacks for 16 points!
 Total damage = 16

The Elf attacks for 22 points!
Magical attack inflicts 22 additional damage points!
 Total damage = 44

The Elf attacks for 5 points!
 Total damage = 5

The Elf attacks for 7 points!
Magical attack inflicts 7 additional damage points!
 Total damage = 14

The Elf attacks for 11 points!
Magical attack inflicts 11 additional damage points!
 Total damage = 22


Examples of Cyberdemon damage:
The Cyberdemon attacks for 39 points!
 Total damage = 39

The Cyberdemon attacks for 53 points!
 Total damage = 53

The Cyberdemon attacks for 54 points!
 Total damage = 54

The Cyberdemon attacks for 36 points!
 Total damage = 36

The Cyberdemon attacks for 47 points!
 Total damage = 47

The Cyberdemon attacks for 53 points!
 Total damage = 53

The Cyberdemon attacks for 45 points!
 Total damage = 45

The Cyberdemon attacks for 5 points!
 Total damage = 5

The Cyberdemon attacks for 28 points!
 Total damage = 28

The Cyberdemon attacks for 27 points!
 Total damage = 27


Examples of Balrog damage:
The Balrog attacks for 8 points!
Balrog speed attack inflicts 7 additional damage points!
 Total damage = 15

The Balrog attacks for 29 points!
Balrog speed attack inflicts 51 additional damage points!
 Total damage = 80

The Balrog attacks for 26 points!
Balrog speed attack inflicts 28 additional damage points!
 Total damage = 54

The Balrog attacks for 76 points!
Balrog speed attack inflicts 18 additional damage points!
 Total damage = 94

The Balrog attacks for 9 points!
Balrog speed attack inflicts 23 additional damage points!
 Total damage = 32

The Balrog attacks for 34 points!
Balrog speed attack inflicts 58 additional damage points!
 Total damage = 92

The Balrog attacks for 37 points!
Balrog speed attack inflicts 57 additional damage points!
 Total damage = 94

The Balrog attacks for 22 points!
Balrog speed attack inflicts 61 additional damage points!
 Total damage = 83

The Balrog attacks for 23 points!
Balrog speed attack inflicts 52 additional damage points!
 Total damage = 75

The Balrog attacks for 63 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 79 additional damage points!
 Total damage = 192


Let the Human vs. Elf Battle Begin!
Human HP:30 Elf HP: 50
The Human attacks for 14 points!
The Elf attacks for 8 points!
Magical attack inflicts 8 additional damage points!
Human HP:14 Elf HP: 36
The Human attacks for 20 points!
The Elf attacks for 29 points!
Magical attack inflicts 29 additional damage points!
Elf wins with HP:16 vs Human HP: -44

Let the Human vs. Cyberdemon Battle Begin!
Human HP:30 Cyberdemon HP: 70
The Human attacks for 3 points!
The Cyberdemon attacks for 14 points!
Human HP:16 Cyberdemon HP: 67
The Human attacks for 2 points!
The Cyberdemon attacks for 30 points!
Cyberdemon wins with HP:65 vs Human HP: -14

Let the Human vs. Balrog Battle Begin!
Human HP:30 Balrog HP: 90
The Human attacks for 19 points!
The Balrog attacks for 50 points!
Balrog speed attack inflicts 54 additional damage points!
Balrog wins with HP:71 vs Human HP: -74

Let the Elf vs. Balrog Battle Begin!
Elf HP:50 Balrog HP: 90
The Elf attacks for 4 points!
The Balrog attacks for 63 points!
Balrog speed attack inflicts 79 additional damage points!
Balrog wins with HP:86 vs Elf HP: -92

Let the Elf vs. Cyberdemon Battle Begin!
Elf HP:50 Cyberdemon HP: 70
The Elf attacks for 39 points!
Magical attack inflicts 39 additional damage points!
The Cyberdemon attacks for 52 points!
It's a tie!

Let the Cyberdemon vs. Balrog Battle Begin!
Cyberdemon HP:70 Balrog HP: 90
The Cyberdemon attacks for 8 points!
The Balrog attacks for 23 points!
Balrog speed attack inflicts 22 additional damage points!
Cyberdemon HP:25 Balrog HP: 82
The Cyberdemon attacks for 33 points!
The Balrog attacks for 61 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 26 additional damage points!
Balrog wins with HP:49 vs Cyberdemon HP: -112

Let the Cyberdemon vs. Balrog Battle Begin!
Cyberdemon HP:10 Balrog HP: 10
The Cyberdemon attacks for 29 points!
The Balrog attacks for 28 points!
Balrog speed attack inflicts 67 additional damage points!
It's a tie!

Let the Cyberdemon vs. Balrog Battle Begin!
Cyberdemon HP:10 Balrog HP: 10
The Cyberdemon attacks for 49 points!
The Balrog attacks for 50 points!
Balrog speed attack inflicts 25 additional damage points!
It's a tie!

Let the Cyberdemon vs. Balrog Battle Begin!
Cyberdemon HP:10 Balrog HP: 10
The Cyberdemon attacks for 19 points!
Demonic attack inflicts 50 additional damage points!
The Balrog attacks for 60 points!
Balrog speed attack inflicts 27 additional damage points!
It's a tie!

mdavis@jarvis:~/school/cis278/a15$
*/
