//
//  Assignment 2
//
//  PriorityQueue.h
//

#ifndef PriorityQueue_h
#define PriorityQueue_h

template <class Item, class Container, class Compare>
class priority_queue {
public:
    void insert(Item item) {
       //
       // Your code goes here . . .
       //
    }

    bool empty() {
        return items.empty();
    }

    Item peak() {
        return itemAt(1);
    }

    void deleteMin() {
       //
       // Your code goes here . . .
       //
    }

private:
    // Abstract the container index into [1, N]
    Item& itemAt(int i) {
        return items[i - 1];
    }

    int count() {
        return (int)items.size();
    }

    void exch(int i, int j) {
       //
       // Your code goes here . . .
       //
    }

    void swim(int i) {
       //
       // Your code goes here . . .
       //
    }

    void sink(int i) {
       //
       // Your code goes here . . .
       //
    }

    Container items;
    Compare compare;
};

#endif /* PriorityQueue_h */
