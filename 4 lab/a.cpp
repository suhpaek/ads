#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

struct BST{
    public:
    Node *root;

    BST(){
        root = NULL;
    }

    Node *insert(Node* node, int val){
        if(node == NULL){
            node = new Node(val);
            return node;
        }

        if(val <= node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);

        return node;
    }
};


int main(){
    BST *bst = new BST();
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        if(bst->root == NULL) bst->root = bst->insert(bst->root, a);
        else bst->insert(bst->root, a);
    }

    while(m--){
        string s; cin >> s;
        Node* cur = bst->root;
        for(int i = 0 ; i < s.size() ; i++){
            if(cur == NULL) break;
            if(s[i] == 'L') cur = cur->left;
            if(s[i] == 'R') cur = cur->right;
        }

        if(cur != NULL) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}