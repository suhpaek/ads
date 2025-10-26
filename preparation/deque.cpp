#include <bits/stdc++.h>>
using namespace std;

int main(){
    int a,k;
    cin>>a>>k;
    vector<int> v(a);
    for(int i=0;i<a;i++){
        cin>>v[i];
    }
    deque<int> d;
    
    for(int i=0; i<v.size();i++){
        if(!d.empty()&&d.front()==i-k){
            d.pop_front();
        }
        while(!d.empty()&& v[d.back()]<v[i]){
            d.pop_back();
        }

        d.push_back(i);
        if(i>=k-1){
            cout<<v[d.front()]<<" ";
        }

    }
}