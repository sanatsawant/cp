#include<iostream>
using namespace std;

const int M=1e9+7;

int powm(int a,int b){
    int ans=1;
    while(b>0){
        if(b&1==1){
            ans=(ans*1LL*a)%M;
        }
        a=(a*1LL*a)%M;
        b>>=1; // b/=2
    }
    return ans;
}
int main(){
    cout<<powm(2,3);
}