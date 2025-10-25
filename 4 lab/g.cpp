#include <iostream>
using namespace std;

struct Node {
    long long val;
    Node* left;
    Node* right;
    Node(long long x) : val(x), left(nullptr), right(nullptr) {}
};

int diameter = 0;

int dfs(Node* node) {
    if (!node) return 0;
    int lh = dfs(node->left);
    int rh = dfs(node->right);
    diameter = max(diameter, lh + rh + 1);
    return max(lh, rh) + 1;
}

Node* insert(Node* root, long long x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insert(root->left, x);
    else if (x > root->val) root->right = insert(root->right, x);
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    if (N == 0) { cout << 0 << "\n"; return 0; }

    Node* root = nullptr;
    for (int i = 0; i < N; ++i) {
        long long x;
        cin >> x;
        root = insert(root, x);
    }

    dfs(root);
    cout << diameter << "\n";
    return 0;
}
