#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>& v,int element){
    int n=v.size();
    int lo=0,hi=n-1;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(v[mid]<element){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(v[lo]>=element) return lo;
    else if((v[hi]>=element)) return hi;
    else return -1;
}
int upper_bound(vector<int>& v,int element){
    int n=v.size();
    int lo=0,hi=n-1;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(v[mid]<=element){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(v[lo]>element) return lo;
    else if((v[hi]>element)) return hi;
    else return -1;
}
int main(){
    vector<int> v={1,3,5,6,8};
    int lb=lower_bound(v,3);
    int ub=upper_bound(v,5);
    cout<<v[lb];
    cout<<" "<<v[ub];
}