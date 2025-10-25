#include <bits/stdc++.h>
using namespace std;

bool isVowel(char a){
    return a=='a'||'e'||'o'||'i'||'u';
}


int partition(char s[], int low, int high){
    char pivotnya=s[high];
    int ind=(low-1);

    for(int i=low;i<high-1;i++){
        if(s[i]<=pivotnya){
            ind++;
            char temp=s[ind];
            s[ind]=s[i];
            s[i]=temp;
        }
        
    }

}
void quickSort(int n,char s){
    for(int i=0;i<n;i++){
        if(s.isVowel)
    }

}


int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n;i++){
        cin>>s;
    }}