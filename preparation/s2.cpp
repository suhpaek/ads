#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
    int* data;
    int top;
    public:
    
    Stack(int size){
        data=new int[size];
        top=-1;
    }
    ~Stack(){
        delete[] data;
    }

    void push(int x){
        top++;
        data[top]=x;
    }

    
    int pop(){
        top--;
        return data[top+1];
    }

  
    int getcur(){
        return data[top];
    }

    int getmax(){
        int max=data[top];
        for(int i=0;i<top;i++){
            if(data[i]>max) max=data[i];
        }
        return max;}

    void print(){
        for (int i=0;i<=top;i++){
            cout<<data[i]<<" ";
        }
    }
};

int main(){
   int n;
   cin>>n;
   Stack steik(n);
    steik.push(9);
    steik.push(0);
    steik.print();
    

}