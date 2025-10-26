#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack <char> st;
    for(char x:s){
        if(st.empty()||x!=st.top()) st.push(x);
        else st.pop(); 
    }

    string res="";
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }

    reverse(res.begin(),res.end());
    cout<<res<<" ";
}