#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    int* data;
    int size;
    int head;
    int tail;
    bool empty;
    bool full;
public:
    Queue(int size){
        data = new int[size];
        this->size = size;
        head = 0;
        tail = 0;
        empty = true;
        full = false;
    }
    ~Queue(){
        delete[] data;
    }

    void tail_enqueue(int x){
        empty = false;
        if(!full){
            data[tail] = x;
            if(tail == size - 1)
                tail = 0;
            else
                tail++;
            if (tail == head)
                full = true;
        }
    }

    int head_dequeue(){
        full = false;
        int x = INT_MIN;
        if(!empty){
            x = data[head];
            if(head == size - 1)
                head = 0;
            else
                head++;
            if(head == tail)
                empty = true;
        }
        return x;
    }

    bool isEmpty(){
        return empty;
    }
};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    Queue S(n*2), K(n*2);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') S.tail_enqueue(i);
        else K.tail_enqueue(i);
    }

    while (!S.isEmpty() && !K.isEmpty()) {
        int i = S.head_dequeue();
        int j = K.head_dequeue();

        if (i < j) {
            S.tail_enqueue(i + n);
        } else {
            K.tail_enqueue(j + n);
        }
    }

    if (S.isEmpty()) cout << "KATSURAGI";
    else cout << "SAKAYANAGI";

    return 0;
}
