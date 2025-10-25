#include <bits/stdc++.h>
using namespace std;

class Queue{
private:
int* data;
int size;
int head;
int tail;
bool empty;
bool full;

public:
Queue(int size){
    data=new int[size];
    this->size=size;

    head=0;
    tail=0;
    empty=true;
    full=false;

}

~Queue(){
    delete[]data;
}

void print(){
    int i= head;
    if(tail==head && full){
        cout<<data[i]<<" ";
        i++;
    }
    while(i!=tail){
        cout<<data[i]<<" ";
        if(i==(size-1))
        i=0;
        else
            i++;
    }
    cout<<endl;
}

void tail_enqueue(int x){
    empty=false;
    if(!full){
        data[tail]=x;
        if(tail==size-1)
        tail=0;
        else
        tail++;
        
        if(tail==head)
        full=true;

    }else{
        cout<<"it is full, can't insert";
    }
}
int head_dequeue(){
        full = false;
        int x = INT_MIN;

        if(!empty){
            x = data[head];

            if(head == size - 1)
                head = 0;
            else
                head++;
            
            if(head == tail)
                empty = true;
        }
        else{
            cout<<"can't return actual number, queue is empty";
        }

        return x;
    }

    void head_enqueue(int x){
        empty = false;

        if(!full){
            if(head==0)
                head = size-1;
            else
                head--;

            data[head] = x;

            if(head==tail)
                full = true;
        }
        else{
            cout<<"it's full, can't insert";
        }
    }

    int tail_dequeue(){
        full = false;
        int x = INT_MIN;

        if(!empty){
            if(tail<=0)
                tail = size-1;
            else
                tail--;
            
            x = data[tail];

            if(tail == head)
                empty = true;
        }
        else{
            cout<<"can't return actual number, queue is empty";
        }
        return x;
    }

    int get(int idx){
        int pos=(head+idx)%size;
        return data[pos];
    }
};


int main(){
    int n;
    cin>>n;

    while(n--){
        int t;
        cin>>t;
        Queue trick(t*2);
        for(int i=t; i>=1;i--){
            trick.head_enqueue(i);
            for(int j=0;j<i;j++){
                int x=trick.tail_dequeue();
                trick.head_enqueue(x);
            }
        }
        for(int i=0;i<t;i++){
            cout<<trick.get(i)<< " ";
        }
        cout<< "\n";
    }


}
