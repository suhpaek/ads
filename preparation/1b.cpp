#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    deque <int> d;

    for(int i=0;i<n;i++){
        while(!d.empty() && d.back()>=a[i]){
            d.pop_back();
        }

        if(d.empty())cout<<"-1"<<" ";
        else cout<<d.back()<<" ";

        d.push_back(a[i]);
    }
    cout<<endl;

}