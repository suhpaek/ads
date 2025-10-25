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

    long long getMax() {
        return a[0];
    }

    void insert(long long k) {
        if (heapSize == capacity) return;
        long long ind = heapSize;
        a[heapSize++] = k;

        while (ind > 0 && a[ind] > a[parent(ind)]) {
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


    class less_cmp{
        public:
        bool operator(int a,int b){
        return a<b;}
    };
    
};

class Heap {
    private:
    int* a;
    int heapsize;
    int capacity;

    int parent(int i){return i=(i-1)/2;}
    int left(int i){return i=i*2-1;}
    int right(int i){return i=i*2-2;}
    public:

    Heap(int cap){
        capacity=cap;
        heapsize=0;
        a=new int [capacity];
    }
    ~Heap(){
        delete[]a;
    }

    int getMin(){
        return a[0];
    }

    int insert(int k){
        if(heapsize==capacity) return;
        int ind=heapsize;
        a[heapsize++]=k;

        if(ind>0 && a[ind]<a[parent(ind)]){
            swap(a[ind],a[parent(ind)]);
            ind=parent(ind);
        }
    }

    int heapify(int i){
        int l=left(i);
        int r=right(i);

        if(l>heapsize) return;
        int j=l;
        if(r<heapsize && a[r]<a[l]) j=r;
        if(a[i]>a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }

    int extractMin(){
        int root=getMin();
        swap(a[0];a[heapsize-1]);
        heapsize--;
        if(heapsize>0) heapify(0);
        return root;
    }

    int findSum(){
        
    }
};