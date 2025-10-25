#include <iostream>
using namespace std;

template<typename type>
class greater_cmp {
public:
    bool operator()(type a, type b) const {
        return (a > b);
    }
};

template<typename type>
class less_cmp {
public:
    bool operator()(type a, type b) const {
        return (a < b);
    }
};

template<typename type, typename compare>
class Heap {
private:
    int size;
    type* arr;
    compare cmp;

    void heapify(int parent) {
        int node = parent, left = node * 2 + 1, right = left + 1;
        if (left < size && cmp(arr[left], arr[node])) node = left;
        if (right < size && cmp(arr[right], arr[node])) node = right;

        if (node != parent) {
            type tmp = arr[node];
            arr[node] = arr[parent];
            arr[parent] = tmp;
            heapify(node);
        }
    }

    void build() {
        for (int i = (size / 2) - 1; i >= 0; i--)
            heapify(i);
    }

    void heapifyUp(int child) {
        int parent = (child - ((child % 2) ? 1 : 2)) / 2;
        if (parent >= 0 && cmp(arr[child], arr[parent])) {
            type tmp = arr[child];
            arr[child] = arr[parent];
            arr[parent] = tmp;
            heapifyUp(parent);
        }
    }

public:
    Heap(type* arr, int size) : size(size), arr(arr) {
        build();
    }

    type extract() {
        type extractable = arr[0];
        arr[0] = arr[--size];
        heapify(0);
        return extractable;
    }

    void insert(type val) {
        arr[size++] = val;
        heapifyUp(size - 1);
    }

    int getSize() const {
        return size;
    }

    type peek() const {
        return arr[0];
    }
};

const int N=1000000+10;
int n, requiredDensity;
int operations=0;
long long a[N];

int main(){
    cin>>n>>requiredDensity;
    for(int i=0;i<n;i++) cin>>a[i];
    Heap<long long, less_cmp<long long>> heap(a,n);

    while(heap.peek()<requiredDensity){
        if(heap.getSize()<=1){
            cout<<-1;
            return 0;
        }

        
        long long least1=heap.extract(), least2=heap.extract();
        heap.insert(least1+2*least2);
        operations++;
    }

    cout<<operations;
}
