template <typename Comparable>

class MaxPQ<Key extends Comparable<Key>> {
    public:
        MaxPQ(int capacity) // or a growable array
            { pq = (Key[ ]) new Comparable[capacity+1]; }
        bool isEmpty( ) { return N == 0; }
        void insert(Key key);
        Key delMax( );
    private:
        void swim(int k);
        void sink(int k, int N);
        bool less(int i, int j)
            { return pq[i].compareTo(pq[j]) < 0; }
        void exch(int i, int j){ Key t = pq[i]; pq[i] = pq[j]; pq[j] = t; }
        Key[ ] pq;
        int N;
}

Key delMax() {
    Key max = pq[1];
    exch(1, N--);
    sink(1, N);
    pq[N+1] = null;
    return max;
}

void sink(int k, int N) {
    while (2*k <= N) {
        int j = 2*k;
        if (j < N && less(j, j+1)) j++;
        if (!less(k, j)) break;
        exch(k, j);
        k = j;
    }
}

void insert(Key x) {
    pq[++N] = x;
    swim(N);
}

void swim(int k) {
    while (k > 1 && less(k/2, k)) {
        exch(k, k/2); // parent of
        k = k/2; // node k is at k/2
    }
}
