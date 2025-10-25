#include <iostream>
using namespace std;

int main(){
    int N;
    if(!(cin>>N))return 0;
    string a[1000000],prev,cur;
    int k=0;
    for(int i=0;i<N;i++){
        cin>>cur;
        if(i==0||cur!=prev)a[k++]=cur;
        prev=cur;
    }
    cout<<"All in all: "<<k<<"\nStudents:\n";
    for(int i=k-1;i>=0;i--)cout<<a[i]<<'\n';
    return 0;
}