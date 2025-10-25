#include <iostream>
using namespace std;

struct Node {
    int v;
    Node* l;
    Node* r;
    Node(int _v) : v(_v), l(nullptr), r(nullptr) {}
};

int insert_get_level(Node*& root, int x) {
    if (!root) { root = new Node(x); return 1; }
    Node* cur = root;
    int level = 1;
    while (true) {
        if (x < cur->v) {
            if (cur->l) { cur = cur->l; ++level; }
            else { cur->l = new Node(x); return level + 1; }
        } else {
            if (cur->r) { cur = cur->r; ++level; }
            else { cur->r = new Node(x); return level + 1; }
        }
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int* p = new int[n];
    for (int i = 0; i < n; ++i) cin >> p[i];

    Node* root = nullptr;
    long long* sum = new long long[n + 2];
    for (int i = 0; i <= n + 1; i++) sum[i] = 0;
    int maxLevel = 0;

    for (int i = 0; i < n; i++) {
        int lvl = insert_get_level(root, p[i]);
        sum[lvl] += p[i];
        if (lvl > maxLevel) maxLevel = lvl;
    }

    cout << maxLevel << "\n";
    for (int i = 1; i <= maxLevel; i++) {
        if (i > 1) cout << ' ';
        cout << sum[i];
    }
    cout << "\n";

    delete[] p;
    delete[] sum;
    return 0;
}
