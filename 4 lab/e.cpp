#include <iostream>
using namespace std;

struct Pair {
    int first;
    int second;
};

struct Queue {
    Pair data[200005];
    int head = 0, tail = 0;
    void push(Pair p) { data[tail++] = p; }
    Pair front() { return data[head]; }
    void pop() { head++; }
    bool empty() { return head == tail; }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    int* L = new int[n + 1];
    int* R = new int[n + 1];
    for (int i = 0; i <= n; i++) { L[i] = 0; R[i] = 0; }

    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) L[x] = y;
        else R[x] = y;
    }

    int* width = new int[n + 2];
    for (int i = 0; i <= n + 1; i++) width[i] = 0;

    Queue q;
    Pair root = {1, 1};
    q.push(root);

    while (!q.empty()) {
        Pair cur = q.front(); q.pop();
        int v = cur.first;
        int lvl = cur.second;
        width[lvl]++;

        if (L[v]) q.push({L[v], lvl + 1});
        if (R[v]) q.push({R[v], lvl + 1});
    }

    int maxW = 0;
    for (int i = 0; i <= n + 1; i++)
        if (width[i] > maxW) maxW = width[i];

    cout << maxW << '\n';

    delete[] L;
    delete[] R;
    delete[] width;
    return 0;
}
