#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back
const int N=1e5+10;
vector<int> g[N];
vector<int> vis(N);
vector<int> level(N);
// TC : O(V + E)
void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int v=q.front();
        cout<<v<<" ";
        q.pop();
        for(auto child:g[v]){
            if(!vis[child]){
                q.push(child);
                level[child]=level[v]+1;
                vis[child]=1;
            }
        }
    }
}

int main() {
    int t=1;
    int n,m;cin>>n>>m;
    for(int i=0;i,i<m-1;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    bfs(1);
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<level[i]<<endl;
    }
    
}
