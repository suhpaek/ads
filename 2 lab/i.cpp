#include <iostream>
using namespace std;

struct Node {
    char val[101];
    Node* next;
    Node* prev;
};

bool equal(const char* a, const char* b) {
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i]) i++;
    return a[i] == b[i];
}

int main() {
    Node* front = nullptr;
    Node* back = nullptr;
    char cmd[20];
    char word[101];

    while (true) {
        if (!(cin >> cmd)) break;

        if (equal(cmd, "add_front")) {
            cin >> word;
            Node* n = new Node;
            int j = 0;
            while ((n->val[j] = word[j])) j++;
            n->next = front;
            n->prev = nullptr;
            if (front) front->prev = n;
            else back = n;
            front = n;
            cout << "ok\n";
        } 
        else if (equal(cmd, "add_back")) {
            cin >> word;
            Node* n = new Node;
            int j = 0;
            while ((n->val[j] = word[j])) j++;
            n->next = nullptr;
            n->prev = back;
            if (back) back->next = n;
            else front = n;
            back = n;
            cout << "ok\n";
        } 
        else if (equal(cmd, "erase_front")) {
            if (!front) cout << "error\n";
            else {
                cout << front->val << '\n';
                Node* t = front;
                front = front->next;
                if (front) front->prev = nullptr;
                else back = nullptr;
                delete t;
            }
        } 
        else if (equal(cmd, "erase_back")) {
            if (!back) cout << "error\n";
            else {
                cout << back->val << '\n';
                Node* t = back;
                back = back->prev;
                if (back) back->next = nullptr;
                else front = nullptr;
                delete t;
            }
        } 
        else if (equal(cmd, "front")) {
            if (!front) cout << "error\n";
            else cout << front->val << '\n';
        } 
        else if (equal(cmd, "back")) {
            if (!back) cout << "error\n";
            else cout << back->val << '\n';
        } 
        else if (equal(cmd, "clear")) {
            while (front) {
                Node* t = front;
                front = front->next;
                delete t;
            }
            back = nullptr;
            cout << "ok\n";
        } 
        else if (equal(cmd, "exit")) {
            cout << "goodbye\n";
            break;
        } 
        else {
            cout << "error\n";
        }
    }

    return 0;
}