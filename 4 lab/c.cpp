#include <iostream>
using namespace std;

struct Node {
    int v;
    Node *l = nullptr, *r = nullptr;
    Node(int _v): v(_v) {}
};

Node* insertBST(Node* t, int x) {
    if (!t) return new Node(x);
    if (x < t->v) t->l = insertBST(t->l, x);
    else          t->r = insertBST(t->r, x);   // равные направо
    return t;
}

Node* findNode(Node* t, int x) {
    while (t && t->v != x) t = (x < t->v) ? t->l : t->r;
    return t;
}

void preorder(Node* t, bool &first) {
    if (!t) return;
    if (!first) cout << ' ';
    cout << t->v;
    first = false;
    preorder(t->l, first);
    preorder(t->r, first);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        root = insertBST(root, a);
    }

    int k; cin >> k;

    Node* sub = findNode(root, k);     // гарантируется, что существует
    bool first = true;
    preorder(sub, first);
    cout << '\n';
    return 0;
}