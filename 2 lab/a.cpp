#include <iostream>
using namespace std;

int main(){
    int a;
    cin>>a;
    int nums[1000000];
    for(int j=0;j<a;j++)cin>>nums[j];
    int target;
    cin>>target;
    int idx=0;
    int best=(nums[0]-target>=0)?(nums[0]-target):-(nums[0]-target);
    for(int k=1;k<a;k++){
        int d=(nums[k]-target>=0)?(nums[k]-target):-(nums[k]-target);
        if(d<best){
            best=d;
            idx=k;
        }
    }
    cout<<idx;
}