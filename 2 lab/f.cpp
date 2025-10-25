#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[200000];
    for(int i=0;i<n;i++)cin>>a[i];
    int data,pos;
    cin>>data>>pos;
    for(int i=n;i>pos;i--)a[i]=a[i-1];
    a[pos]=data;
    n++;
    for(int i=0;i<n;i++){
        if(i>0)cout<<' ';
        cout<<a[i];
    }
    cout<<'\n';
}