#include<bits/stdc++.h>
using namespace std;

const int N=1e7+10;
vector<bool> isPrime(N,1);
vector<int> hp(N,0),lp(N,0);
int main(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<N;i++){
        if(isPrime[i]==true){
            lp[i]=hp[i]=i; 
            for(int j=i*2;j<N;j+=i){
                isPrime[j]=false;
                hp[j]=i;
                if(lp[j]==0) lp[j]=i;
            }
        }
    }

    // N * log(logN)
    for(int i=1;i<100;i++) cout<<hp[i]<<" "<<lp[i]<<endl;
    
}