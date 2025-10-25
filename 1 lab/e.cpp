#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    int* data;
    int size;
    int head;
    int tail;
    bool emptyFlag;
    bool full;

public:
    Queue(int size) {
        data = new int[size];
        this->size = size;
        head = 0;
        tail = 0;
        emptyFlag = true;
        full = false;
    }

    ~Queue() {
        delete[] data;
    }

    void tail_enqueue(int x) {
        emptyFlag = false;
        if (!full) {
            data[tail] = x;
            if (tail == size - 1) tail = 0;
            else tail++;
            if (tail == head) full = true;
        }
    }

    int head_dequeue() {
        full = false;
        int x = INT_MIN;
        if (!emptyFlag) {
            x = data[head];
            if (head == size - 1) head = 0;
            else head++;
            if (head == tail) emptyFlag = true;
        }
        return x;
    }

    bool isEmpty() {
        return emptyFlag;
    }
};

int main() {
    Queue boris(1000), nursik(1000);

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        boris.tail_enqueue(x);
    }
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        nursik.tail_enqueue(x);
    }

    int moves = 0;
    const int LIMIT = 1000000;

    while (!boris.isEmpty() && !nursik.isEmpty() && moves < LIMIT) {
        moves++;
        int b = boris.head_dequeue();
        int n = nursik.head_dequeue();

        if ((b == 0 && n == 9) || (b > n && !(b == 9 && n == 0))) {
            boris.tail_enqueue(b);
            boris.tail_enqueue(n);
        } else {
            nursik.tail_enqueue(b);
            nursik.tail_enqueue(n);
        }
    }

    if (moves >= LIMIT) cout << "blin nichya";
    else if (boris.isEmpty()) cout << "Nursik " << moves;
    else cout << "Boris " << moves;
}
