#include <bits/stdc++.h>

using namespace std;

class Stack {
private:
    int* data;
    int top;
    int capacity;

public:
    Stack(int size){
        data=new int[size];
        capacity=size;
        top=-1;
    }

    ~Stack(){
        delete[] data;
    }
    
    void push(int x){
        if(top + 1 == capacity){
            return;
        }
        data[++top]=x;
    }
    
    int pop(){
        if(empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return data[top--];
    }
    
    int getTop(){
        if (top == -1) return -1;
        return data[top];
    }

    bool empty(){
        return top == -1;
    }
};





int main(){
    int n;
    cin>>n;
    int* arr_input = new int[n];

    for( int i=0; i<n; i++){
        cin>> arr_input[i];
    }


    int* arr_output = new int[n];

    Stack pot_neighb(n);

    for( int i=0; i<n; i++){
        
        while(!pot_neighb.empty() && pot_neighb.getTop()>arr_input[i]){
            pot_neighb.pop();
        }

        if(pot_neighb.empty()){
            arr_output[i]=-1;
        }
        else{
            arr_output[i]=pot_neighb.getTop();
        }

        pot_neighb.push(arr_input[i]);
    }

    for(int i=0;i<n;i++){
        cout<<arr_output[i]<<" ";
    }



    delete[] arr_input;
    delete[] arr_output;
    return 0;
}