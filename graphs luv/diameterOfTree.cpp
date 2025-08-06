#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back

//consider any vertex as root and
//find max depth node from this vertex
// now with this node as root find
// max depth , this is the diameter 
//of tree

const int N=1e5+10;
vector<int> g[N];
int depth[N];

void dfs(int v,int par=0){
    for(auto child:g[v]){
        if(child==par) continue;
        depth[child]=depth[v]+1;
        dfs(child,v);
    }
}

int main() {
    int t=1;
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    int mxdepth=-1;
    int mxdepthnode;
    dfs(1);
    for(int i=1;i<=n;i++){
        if(mxdepth<depth[i]){
            mxdepth=depth[i];
            mxdepthnode=i;
        }
        depth[i]=0;
    }
    dfs(mxdepthnode);
    for(int i=1;i<=n;i++){
        if(mxdepth<depth[i]){
            mxdepth=depth[i];
            mxdepthnode=i;
        }
        depth[i]=0;
    }
    cout<<mxdepth<<endl;


}
