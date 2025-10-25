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
            type temp = arr[node];
            arr[node] = arr[parent];
            arr[parent] = temp;
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
            type temp = arr[child];
            arr[child] = arr[parent];
            arr[parent] = temp;
            heapifyUp(parent);
        }
    }

public:
    Heap(type* arr, int size) : size(size), arr(arr) {
        build();
    }

    void print() const {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
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
};

const int N=200000+10;
int n;
long long sum=0;
long long a[N];

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    Heap<long long,greater_cmp<long long>> heap(a,n);
    while(heap.getSize()>1){
        long long y=heap.extract();
        long long x=heap.extract();
        if(x!=y) heap.insert(y-x);
    }

    cout<<((heap.getSize()==1)?heap.extract():0);
}
