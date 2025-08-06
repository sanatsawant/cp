#include<iostream>
using namespace std;

const int M=1e9+7;

// *** DONT USE THIS ***
int powm(int a,int b){
    if(b==0) return 1;
    int res=powm(a,b/2);
    if(b&1){ // b is odd
        return (a*(res*1LL*res)%M)%M;
    }
    else{
        return (res*1LL*res)%M;
    }
}
int main(){
    cout<<powm(2,3);
}