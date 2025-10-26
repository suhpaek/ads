#include <bits/stdc++.h>

class Node{
    private:
    Node* parent;
    Node* left;
    Node* right;
    int data;
    
    public:

    Node(int data){
        parent=nullptr;
        left=nullptr;
        right=nullptr;
        this->data=data;
    }

    int getData(){
        return data;
    }

    void setLeft(Node* newLeft){
        left=newLeft;
    }

    void setRight(Node* newRight){
        right=newRight;
    }

    void setParent(Node* newParent){
        parent=newParent;
    }

    Node* getLeft(){
        return left;
    }

    Node* getRight(){
        return right;
    }

    Node* getParent(){
        return right;
    }

};

class BST{
    private:
    Node* root;
    
    public:
    BST(){
        root=nullptr;
    }
    void insert(int newData){
        Node* newNode=new Node(newData);

        Node* x=root;
        Node* y=nullptr;
        
        while(x){
            if(x->getData()>newData){
                y=x;
                x=x->getLeft();
            }
            else{
                y=x;
                x=x->getRight();
            }
        }

        if(y=nullptr){
            root=newNode;
        }
        else{
            if(newData>y->getData()){
                y->setRight(newNode);
            }
            else{
                y->setLeft(newNode);
            }
            newNode->setParent(y);
        }
    }

    void inOrder(Node* n){
        if(n){
            inOrder(n->getLeft());
            std::cout<<n->getData()<<" ";
            inOrder(n->getRight());
        }
    }

    void print(){
        inOrder(root);
    }

    void clear(Node *n){
        if(n){
        clear(n->getLeft());
        clear(n->getRight());
        delete n;}
    }

    ~BST(){
        clear(root);
    }


};

int main(){
    int n;
    std::cin>>n;

    BST bsbs;
    for(int i=0;i<n;i++){
        bsbs.insert(i);
    }
    
}