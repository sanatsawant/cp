#include<iostream>
using namespace std;
int main(){
    int n=5;
    int a[n]={2,3,6,7,8};
    int lo=0,hi=n-1;
    int to_find=7;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(a[mid]<to_find){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(a[lo]==to_find){
        cout<<lo<<endl;
    }
    else if(a[hi]==to_find){
        cout<<hi<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
}