#include <iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)cin>>a[i];
    int freq[1000];
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=0;j<n;j++)if(a[i]==a[j])c++;
        freq[i]=c;
    }
    int mx=freq[0];
    for(int i=1;i<n;i++)if(freq[i]>mx)mx=freq[i];
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]<a[j]){
                int t=a[i];a[i]=a[j];a[j]=t;
                t=freq[i];freq[i]=freq[j];freq[j]=t;
            }
    for(int i=0;i<n;i++){
        bool used=false;
        for(int j=0;j<i;j++)if(a[i]==a[j]){used=true;break;}
        if(!used&&freq[i]==mx)cout<<a[i]<<' ';
    }
}