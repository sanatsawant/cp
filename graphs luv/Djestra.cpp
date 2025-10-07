#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back
#define M 1000000007
const int N=1e5+10;
vector<pair<int,ll>> g[N];
vector<ll> dist(N,1e17);
int vis[N];
void solve(){
    int n,m;cin>>n>>m;
    dist[1]=0;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].pb(make_pair(v,w));
    }
 
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q; //minheap
    q.push(make_pair(0,1));
    while(!q.empty()){
        auto t=q.top();
        q.pop();
        // if(t[0] > dist[t[1]] ) continue;     //stale entry check  // alternative for vis array
        if(vis[t.second]) continue;
        vis[t.second]=1;
        for(auto child:g[t.second]){
            if(vis[child.first]) continue;
            if(dist[t.second] + child.second < dist[child.first]){
                dist[child.first]=dist[t.second] + child.second;
                q.push(make_pair(dist[child.first],child.first));
            }
            
        }
    }
    for(int i=1;i<=n;i++) cout<<dist[i]<<' ';
    cout<<'\n';
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }
}
