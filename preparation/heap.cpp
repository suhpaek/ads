#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin>>n>>k;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i=1;i<=n;i++){
        long long a;
        cin>>a;
        pq.push(a);

        if(pq.size()>k){
            pq.pop();
        }

        if(i<k){
            cout<<"bocchi\n";
        }else{
            cout<<pq.top();
        }
    }
}