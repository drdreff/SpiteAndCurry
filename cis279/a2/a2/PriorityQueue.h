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
        items.push_back(item);
        swim(count());
    }

    bool empty() {
        return items.empty();
    }

    Item peak() {
        return itemAt(1);
    }

    void deleteMin() {
        exch(1, count());
        items.pop_back();
        sink(1);
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
        Item temp = itemAt(i);
        items[ i - 1] = itemAt(j);
        items[ j - 1] = temp;
    }

    void swim(int i) {
        while (i > 1 && (compare(itemAt(i/2),itemAt(i))) ) {
            exch(i, i/2);
            i = i/2;
        }
    }

    void sink(int i) {
        while (2*i <= count()) {
            int j = 2*i;
            if (j < count() && (compare(itemAt(j),itemAt(j+1)))) j++;
            if (!(compare(itemAt(i),itemAt(j)))) break;
            exch(i, j);
            i = j;
        }
    }

    Container items;
    Compare compare;
};

#endif /* PriorityQueue_h */
