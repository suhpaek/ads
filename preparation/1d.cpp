#include <bits/stdc++.h>
#include <deque>

using namespace std;

bool isBalanced(string s){
    deque <string> d;
    for(char x:s){
        d.push_back(string(1,x));
    }

    string p=d.front();
    for(int i=0;i<d.size();i++){
        while(d.front()==d.back()){
            d.pop_back();
        }
        if(p==d.front()){
            d.pop_front();
        }
    }
}

int main(){
    string s;
    cin>>s;
    
}