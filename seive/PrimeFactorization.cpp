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

    vector<int> pf;
    int num;cin>>num;
    while(num>1){
        int prime_factor=lp[num];
        while(num%prime_factor==0){
            pf.push_back(prime_factor);
            num/=prime_factor;
        }
    }
    // while(num>1){
    // int prime_factor=hp[num];
    //     while(num%prime_factor==0){
    //         pf.push_back(prime_factor);
    //         num/=prime_factor;
    //     }
    // }


 
    for(auto x:pf) cout<<x<<" ";
    
}