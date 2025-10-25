#include <bits/stdc++.h>
using namespace std;

int main(){
   long long n,sum=0;
   cin>>n;
   priority_queue<long long, vector<long long>, greater<long long>> pq;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    pq.push(x);
   }

   for(int i=0;i<n-1;i++){
    long long x=pq.top();
    pq.pop();
    long long comb=x+pq.top();
    pq.pop();
    pq.push(comb);
    sum+=comb;
   }
   cout<<sum;
}
