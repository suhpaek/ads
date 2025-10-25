#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};



class Linked{
    public:

    int sz;
    Node *head, *tail;

    Linked() {
        sz = 0;
        head = tail = NULL;
    }


    void push_front(int data){
        Node* new_node = new Node(data);
        if (sz == 0)
        {
            head = tail = new_node;
        }
        else
        {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
        sz++;
        
    }
    void push_back(int data){
        Node* new_node = new Node(data);
        if (sz == 0)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        sz++;
        
    }
};