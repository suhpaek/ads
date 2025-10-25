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
    string s1,s2;
    cin>>s1>>s2;
    string o1="", o2="";
    Stack st1(pow(10,5));
    for (int i = 0; i < s1.size(); i++){
        if(s1[i]=='#'){
            st1.pop();
        } else {
            st1.push(s1[i]);
        }
    }
    while(!st1.empty()){
        o1.push_back(st1.getTop());
        st1.pop();
    }
    reverse(o1.begin(), o1.end());
    Stack st2(pow(10,5));
    for (int i = 0; i < s2.size(); i++){
        if(s2[i]=='#'){
            st2.pop();
        } else {
            st2.push(s2[i]);
        }
    }
    while(!st2.empty()){
        o2.push_back(st2.getTop());
        st2.pop();
    }
    reverse(o2.begin(), o2.end());
    if(o1==o2){
        cout<<"Yes";
    } else {
        cout<<"No";
    }
}
