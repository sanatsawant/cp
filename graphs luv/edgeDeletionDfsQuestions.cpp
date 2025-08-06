#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back
const int N=1e5+10;
const int M=1e9+7;
vector<int> g[N];
int subtree_sum[N];

void dfs(int vertex,int par=0){
    subtree_sum[vertex]+=vertex;
    for(int child:g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
    }
}
int main() {
    int m;cin>>m;
    for(int i=0;i<m-1;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    dfs(1); 
    ll ans=-1;
    for(int i=2;i<=m;i++){
        int part1=subtree_sum[i];
        int part2=subtree_sum[1]-part1;
        ans=max(ans,(part1 * 1LL * part2)%M);
    }
    cout<<ans<<"\n";
    
}