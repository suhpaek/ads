#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        deque<int>d;
        for(int i=n;i>=1;i--){
            d.push_front(i);
            for(int j=0; j<i;j++){
                d.push_front(d.back());
                d.pop_back();
            }
        }

        for(int x:d) cout<<x<<" ";
        cout<<'\n';
    }
}



