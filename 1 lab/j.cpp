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
    Queue(int size) {
        data = new int[size];
        this->size = size;
        head = 0;
        tail = 0;
        empty = true;
        full = false;
    }

    ~Queue() {
        delete[] data;
    }

    void tail_enqueue(int x) {
        empty = false;
        if (!full) {
            data[tail] = x;
            if (tail == size - 1) tail = 0;
            else tail++;
            if (tail == head) full = true;
        }
    }

    void head_enqueue(int x) {
        empty = false;
        if (!full) {
            if (head == 0) head = size - 1;
            else head--;
            data[head] = x;
            if (head == tail) full = true;
        }
    }

    int head_dequeue() {
        full = false;
        if (!empty) {
            int x = data[head];
            if (head == size - 1) head = 0;
            else head++;
            if (head == tail) empty = true;
            return x;
        }
        return INT_MIN;
    }

    int tail_dequeue() {
        full = false;
        if (!empty) {
            if (tail == 0) tail = size - 1;
            else tail--;
            int x = data[tail];
            if (head == tail) empty = true;
            return x;
        }
        return INT_MIN;
    }

    bool isEmpty() {
        return empty;
    }

    int front() {
        if (empty) return INT_MIN;
        return data[head];
    }

    int back() {
        if (empty) return INT_MIN;
        int pos = (tail == 0 ? size - 1 : tail - 1);
        return data[pos];
    }
};

int main() {

    Queue dq(200000);

    char op;
    while (cin >> op) {
        if (op == '!') break;
        if (op == '+') {
            int x;
            cin >> x;
            dq.head_enqueue(x);
        } else if (op == '-') {
            int x; 
            cin >> x;
            dq.tail_enqueue(x);
        } else if (op == '*') {
            if (dq.isEmpty()) {
                cout << "error\n";
            } else {
                int f = dq.front();
                int b = dq.back();
                dq.head_dequeue();
                if (!dq.isEmpty()) dq.tail_dequeue();
                else b = f;
                cout << f + b << "\n";
            }
        }
    }
    return 0;
}
