#include <iostream>
using namespace std;

struct Node {
    long long v;
    Node *l = nullptr, *r = nullptr;
    Node(long long _v) : v(_v) {}
};

Node* insertBST(Node* t, long long x) {
    if (!t) return new Node(x);
    if (x < t->v) t->l = insertBST(t->l, x);
    else          t->r = insertBST(t->r, x); // равные кладём вправо
    return t;
}

Node* findNode(Node* t, long long x) {
    while (t && t->v != x) t = (x < t->v) ? t->l : t->r;
    return t;
}

int subSize(Node* t) {
    if (!t) return 0;
    return 1 + subSize(t->l) + subSize(t->r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    if (!(cin >> N)) return 0;

    Node* root = nullptr;
    for (int i = 0; i < N; ++i) {
        long long a; cin >> a;
        root = insertBST(root, a);
    }

    long long X; 
    cin >> X;

    Node* target = findNode(root, X);
    cout << (target ? subSize(target) : 0) << '\n';
    return 0;
}