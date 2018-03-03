#include <iostream>
using namespace std;

const int NUM_DISKS = 27;

void moveDisks(int numDisks,
               string source,
               string target,
               string storage);

int main()
{
    moveDisks(NUM_DISKS, "LEFT", "RIGHT", "MIDDLE");
}


void moveDisks(int numDisks,
               string source,
               string target,
               string storage)
{
    if (numDisks > 0){
        moveDisks(numDisks - 1, source, storage, target);
        // cout << "move a disk from the " << source
        //      << " tower to the " << target << " tower." << endl;
        moveDisks(numDisks - 1, storage, target, source);
    }
}
