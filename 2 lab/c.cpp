#include <iostream>
using namespace std;

struct Node{int x;Node*next;};
int main(){
    int n;cin>>n;
    Node*head=nullptr,*tail=nullptr;
    for(int i=0;i<n;i++){
        Node*t=new Node;
        cin>>t->x;
        t->next=nullptr;
        if(!head)head=tail=t;
        else{tail->next=t;tail=t;}
    }
    Node*p=head,*prev=nullptr;
    int c=1;
    while(p){
        if(c%2==0){
            prev->next=p->next;
            delete p;
            p=prev->next;
        }else{
            prev=p;
            p=p->next;
        }
        c++;
    }
    p=head;
    while(p){cout<<p->x<<' ';p=p->next;}
}