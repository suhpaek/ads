#include <bits/stdc++.h>>
using namespace std;

int main(){
    int n;
    int tar;
    cin>>n>>tar;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    auto it=lower_bound(v.begin(), v.end(), tar);
    
    if(it==v.end()){
        cout<<"-1";
    }
    else{
        cout<<it-v.begin();
    }
}