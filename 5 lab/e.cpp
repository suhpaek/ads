#include <iostream>
using namespace std;

template<typename T>
void mySwap(T &a, T &b) {
    T t = a; a = b; b = t;
}

template<typename T>
class Less {
public:
    bool operator()(T a, T b) const {
        return a < b;
    }
};

template<typename T, typename Compare>
class Heap {
private:
    T* arr;
    int size;
    Compare cmp;

    void heapify(int i) {
        int smallest = i, left = 2*i + 1, right = 2*i + 2;
        if (left < size && cmp(arr[left], arr[smallest])) smallest = left;
        if (right < size && cmp(arr[right], arr[smallest])) smallest = right;
        if (smallest != i) {
            mySwap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && cmp(arr[i], arr[parent])) {
            mySwap(arr[i], arr[parent]);
            heapifyUp(parent);
        }
    }

public:
    Heap(T* storage) : arr(storage), size(0) {}

    void insert(T val) {
        arr[size] = val;
        heapifyUp(size);
        size++;
    }

    T extract() {
        T root = arr[0];
        arr[0] = arr[--size];
        heapify(0);
        return root;
    }

    T peek() const {
        return arr[0];
    }

    int getSize() const {
        return size;
    }
};

const int N=1000010;
long long a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q,k;
    cin>>q>>k;

    Heap<long long, Less<long long>> heap(a);
    long long total=0;

    while(q--){
        string cmd;
        cin>>cmd;

        if(cmd=="print"){
            cout<<total<<"\n";
        } else{
            long long x;
            cin>>x;

            if(heap.getSize()<k) {
                heap.insert(x);
                total+=x;
            } else if(x>heap.peek()){
                total-=heap.peek();
                heap.extract();
                heap.insert(x);
                total+=x;
            }
        }
    }
}
