#include <iostream>
#include <ctime>
#include <cstdlib>
#include "IntegerQueue.h"


using namespace std;

int main(){
    srand(time(0));
    MinPQ myHeap;

    for (int i=1;i!=20;i++){
        int num = (rand() % 100) + 1 ;
        cout << num << endl;
        // put it on the heap
        myHeap.insert(num);
    }
    cout << "heap:" << endl;
    // dump heap
    while (!myHeap.isEmpty()){
        cout << myHeap.delMin() << endl;
    }
}
