#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back

const int N=1e5+10;
vector<int> graph[N];
vector<bool> vis(N);

bool dfs(int vertex,int par){
    vis[vertex]=true;
    bool cyclePresent=false;
    for(auto child:graph[vertex]){
        if(child==par && vis[child]==true){
            continue;
        }
        if(vis[child]){
            return true;
        }
        cyclePresent|=dfs(child,vertex);
    }
    return cyclePresent;
}

int main() {
   int n,m;cin>>n>>m;
   for(int i=0;i<m;i++){
        int v1,v2;cin>>v1>>v2;
        graph[v1].pb(v2);
        graph[v2].pb(v1);
   }
   bool cyclePresent=false;
   for(int i=0;i<n;i++){
        if(dfs(0,-1)){
            cyclePresent=true;
            break;
        }
   }
   cout<<cyclePresent<<endl;
}
