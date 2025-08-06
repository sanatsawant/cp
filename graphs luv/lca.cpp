#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back

// to find lca between two nodes
//1. store the parents of all nodes in par[N] array
//2. compute the path from the root to the nodes using path func
//3. the first common node between both paths is lca
//4. eg x=7  y=12
//   path_x = 1->2->5->7
//   path_y = 1->2->5->8->12  5 is lca

// study binary lifting algo -> tc: log(n) finding lca

const int N=1e5+10;
vector<int> g[N];
int par[N];
vector<int> path(int v){
    vector<int> ans;
    while(v!=-1){
        ans.pb(v);
        v=par[v];
    }
    reverse(all(ans));
    return ans;
}

void dfs(int vertex,int p=-1){
     par[vertex]=p;
    for(auto child:g[vertex]){
        if(child==p) continue;
        dfs(child,vertex);
       
    }
}
int main() {
    int m;cin>>m;
    for(int i=0;i<m-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    dfs(1);
    int x,y;cin>>x>>y;
    vector<int> path_x=path(x);
    vector<int> path_y=path(y);
    int len=min(path_x.size(),path_y.size());
    int lca;
    for(int i=0;i<len;i++){
        if(path_x[i]==path_y[i]){
            lca=path_x[i];
        }
        else break;
    }
    cout<<lca<<endl;
        
}
