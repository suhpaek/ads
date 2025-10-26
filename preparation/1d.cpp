#include <bits/stdc++.h>
#include <deque>

using namespace std;

bool isBalanced(string s){
    deque <char> d;
    for(char x:s){
        if(!d.empty() && d.back() == x){
        d.pop_back();
        }
        else{
        d.push_back(x);
        }
    }


    return d.empty();
    

}

int main(){
    string s;
    cin>>s;
    if (isBalanced(s)) cout<<"YES";
    else cout<<"NO";
}