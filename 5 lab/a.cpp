#include <iostream>
using namespace std;

class Heap {
private:
    long long* a;
    long long heapSize;
    long long capacity;

    long long parent(long long i) { return (i - 1) / 2; }
    long long left(long long i) { return 2 * i + 1; }
    long long right(long long i) { return 2 * i + 2; }

public:
    Heap(long long cap) {
        capacity = cap;
        heapSize = 0;
        a = new long long[capacity];
    }

    ~Heap() {
        delete[] a;
    }

    long long getMin() {
        return a[0];
    }

    void insert(long long k) {
        if (heapSize == capacity) return;
        long long ind = heapSize;
        a[heapSize++] = k;

        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(long long i) {
        long long l = left(i);
        long long r = right(i);
        if (l >= heapSize) return;
        long long j = l;
        if (r < heapSize && a[r] < a[l]) j = r;
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    long long extractMin() {
        long long root_value = getMin();
        swap(a[0], a[heapSize - 1]);
        heapSize--;
        if (heapSize > 0) heapify(0);
        return root_value;
    }

    long long findSum(long long sum) {
        while (heapSize > 1) {
            long long min1 = extractMin(), min2 = extractMin();
            long long comb = min1 + min2;
            sum+=comb;
            insert(comb);
        }
        return sum;
    }
};

int main(){
    long long n;
    cin>>n;
    Heap heap(100000);
    for(long long i=0;i<n;i++){
        long long x;
        cin>>x;
        heap.insert(x);
    }
    cout<<heap.findSum(0);
}
