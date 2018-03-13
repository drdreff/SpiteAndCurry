#include <vector>

class MinPQ {
    public:
        MinPQ();
        bool isEmpty( );
        void insert(int x);
        int delMin( );
    private:
        void swim(int k);
        void sink(int k, int N);
        void swap(int i, int j);
        std::vector<int> pq; // first element gets 0
        int N;
};

MinPQ::MinPQ(){
    // on construct, prefill the zeroth element
    pq.push_back(0);
}

bool MinPQ::isEmpty( ){
    return (N == 0);
}

void MinPQ::insert(int x) {
    pq.push_back(x);
    MinPQ::swim(++N);
}

int MinPQ::delMin() {
    int min = pq[1];
    MinPQ::swap(1, N--);
    MinPQ::sink(1, N);
    pq.pop_back();
    return min;
}

void MinPQ::swim(int k) {
    while (k > 1 && (pq[k/2] > pq[k])) {
        MinPQ::swap(k, k/2); // parent of
        k = k/2; // node k is at k/2
    }
}

void MinPQ::sink(int k, int N) {
    while (2*k <= N) {
        int j = 2*k;
        if (j < N && (pq[j] > pq[j+1])) j++;
        if (!(pq[k] > pq[j])) break;
        MinPQ::swap(k, j);
        k = j;
    }
}

void MinPQ::swap(int i, int j){
    int temp = pq[i];
    pq[i] = pq[j];
    pq[j] = temp;
}
