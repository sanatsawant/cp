#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back

const int N=1e5+10;
vector<int> g[N];
int height[N],depth[N];

void dfs(int vertex,int par=0){

    for(auto child:g[vertex]){
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);
    }
}
int main() {
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
   
    dfs(1);
    for(int i=1;i<=13;i++) cout<<depth[i]<<" "<<height[i]<<endl; 
        
}
