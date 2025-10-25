#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    char* data;
    int size;
    int head;
    int tail;
    bool emptyFlag;
    bool full;

public:
    Queue(int size){
        data = new char[size];
        this->size = size;
        head = 0;
        tail = 0;
        emptyFlag = true;
        full = false;
    }

    ~Queue(){
        delete[] data;
    }

    void tail_enqueue(char x){
        emptyFlag = false;
        if(!full){
            data[tail] = x;
            if(tail == size - 1) tail = 0;
            else tail++;
            if(tail == head) full = true;
        }
    }

    char tail_dequeue(){
        full = false;
        char x = '\0';
        if(!empty()){
            if(tail <= 0) tail = size - 1;
            else tail--;
            x = data[tail];
            if(tail == head) emptyFlag = true;
        }
        return x;
    }

    char get(int idx){
        int pos = (head + idx) % size;
        return data[pos];
    }

    bool empty(){
        return emptyFlag;
    }

    int getSize(){
        if(tail >= head) return tail - head;
        else return size - head + tail;
    }
};

int main(){
    string s;
    cin >> s;

    Queue q(s.size());

    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(q.empty() || q.get(q.getSize() - 1) != c){
            q.tail_enqueue(c);
        } else {
            q.tail_dequeue();
        }
    }

    if(q.empty()) cout << "YES";
    else cout << "NO";

    return 0;
}
