#include <iostream>
using namespace std;
struct Node{string w;Node*next;};
int main(){
    int n,k;
    cin>>n>>k;
    Node*head=nullptr,*tail=nullptr;
    for(int i=0;i<n;i++){
        Node*t=new Node;
        cin>>t->w;
        t->next=nullptr;
        if(!head)head=tail=t;else{tail->next=t;tail=t;}
    }
    if(n==0)return 0;
    k%=n;
    if(k==0){Node*p=head;while(p){cout<<p->w<<' ';p=p->next;}return 0;}
    tail->next=head;
    Node*nt=head;
    for(int i=1;i<k;i++)nt=nt->next;
    Node*nh=nt->next;
    nt->next=nullptr;
    Node*p=nh;
    while(p){cout<<p->w<<' ';p=p->next;}
}