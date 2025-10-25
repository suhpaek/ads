#include <iostream>
using namespace std;

struct Node {
    long long key;
    long long count;
    Node* left;
    Node* right;
    Node(long long k) : key(k), count(1), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, long long x) {
    if (!root) return new Node(x);
    if (x < root->key) root->left = insert(root->left, x);
    else if (x > root->key) root->right = insert(root->right, x);
    else root->count++;
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* remove(Node* root, long long x) {
    if (!root) return nullptr;
    if (x < root->key) root->left = remove(root->left, x);
    else if (x > root->key) root->right = remove(root->right, x);
    else {
        if (root->count > 1) root->count--;
        else {
            if (!root->left) {
                Node* tmp = root->right;
                delete root;
                return tmp;
            } else if (!root->right) {
                Node* tmp = root->left;
                delete root;
                return tmp;
            } else {
                Node* tmp = findMin(root->right);
                root->key = tmp->key;
                root->count = tmp->count;
                tmp->count = 1;
                root->right = remove(root->right, tmp->key);
            }
        }
    }
    return root;
}

long long getCount(Node* root, long long x) {
    while (root) {
        if (x < root->key) root = root->left;
        else if (x > root->key) root = root->right;
        else return root->count;
    }
    return 0;
}

int main() {
    int Q;
    if (!(cin >> Q)) return 0;
    Node* root = nullptr;
    for (int i = 0; i < Q; ++i) {
        string op; long long x;
        cin >> op >> x;
        if (op == "insert") root = insert(root, x);
        else if (op == "delete") root = remove(root, x);
        else if (op == "cnt") cout << getCount(root, x) << '\n';
    }
    return 0;
}
