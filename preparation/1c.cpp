#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    char target= '#';
    deque<string>d1,d2;

    for(char x : s1){
        if(x!=target){
            d1.push_back(string(1,x));
        }
        else d1.pop_back();
    }

    for(char x : s2){
        if(x!=target){
            d2.push_back(string(1,x));
        }
        else d2.pop_back();
    }

    if(d1==d2) cout<<"Yes";
    else cout<<"No";
}