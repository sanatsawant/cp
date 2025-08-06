#include<bits/stdc++.h>
using namespace std;

#define eps 1e-6  // find nth root accurate upto 5 decimal places

double multiply(double mid,int n){
    double ans=1;
    for(int i=1;i<=n;i++) ans*=mid;
    return ans;
}
int main(){
    double x;
    int n;
    cin>>x>>n;
    double lo=1,hi=x,mid;
    while(hi-lo>eps){
        mid=(lo+hi)/2;
        if(multiply(mid,n) < x){
            lo=mid;
        }
        else{
            hi=mid;
        }
    }
    cout<<setprecision(10)<<lo<<"\n";
    cout<<pow(2,1.0/n)<<"\n";

}