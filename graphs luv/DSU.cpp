#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back
#define M 1000000007
const int N=1e5+10;


int parent[N];
int size[N];

void make(int v){
    parent[v]=v;
    size[v]=1;
}

int find(int v){
    if(parent[v]==v) return v;
    //path compression
    else return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    //union by size
    if(size[a]<size[b]) swap(a,b);
    if(a!=b){
        parent[b]=a;
        size[a]+=size[b];
    }

}
// TC is almost constt
void solve(){
    
    
}

int main() {
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
