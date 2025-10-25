#include <iostream>
using namespace std;

int main(){
    int L[1000000], n=0;
    while(true){
        int cmd;
        if(!(cin>>cmd))break;
        if(cmd==0)break;
        if(cmd==1){
            int x,p;cin>>x>>p;
            for(int i=n;i>p;i--)L[i]=L[i-1];
            L[p]=x;
            n++;
        }
        else if(cmd==2){
            int p;cin>>p;
            for(int i=p;i<n-1;i++)L[i]=L[i+1];
            n--;
        }
        else if(cmd==3){
            if(n==0)cout<<-1<<'\n';
            else{
                for(int i=0;i<n;i++){
                    if(i>0)cout<<' ';
                    cout<<L[i];
                }
                cout<<'\n';
            }
        }
        else if(cmd==4){
            int p1,p2;cin>>p1>>p2;
            int val=L[p1];
            for(int i=p1;i<n-1;i++)L[i]=L[i+1];
            n--;
            for(int i=n;i>p2;i--)L[i]=L[i-1];
            L[p2]=val;
            n++;
        }
        else if(cmd==5){
            for(int i=0;i<n/2;i++){
                int t=L[i];
                L[i]=L[n-1-i];
                L[n-1-i]=t;
            }
        }
        else if(cmd==6){
            int x;cin>>x;
            if(n>0){
                x%=n;
                if(x){
                    int temp[1000000];
                    int k=0;
                    for(int i=x;i<n;i++)temp[k++]=L[i];
                    for(int i=0;i<x;i++)temp[k++]=L[i];
                    for(int i=0;i<n;i++)L[i]=temp[i];
                }
            }
        }
        else if(cmd==7){
            int x;cin>>x;
            if(n>0){
                x%=n;
                if(x){
                    int temp[1000000];
                    int k=0;
                    for(int i=n-x;i<n;i++)temp[k++]=L[i];
                    for(int i=0;i<n-x;i++)temp[k++]=L[i];
                    for(int i=0;i<n;i++)L[i]=temp[i];
                }
            }
        }
    }
    return 0;
}