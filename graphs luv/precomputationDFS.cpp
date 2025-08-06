#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back
const int N=1e5+10;
vector<int> g[N];

// given Q queries
// in each query given V
// calc subtree sum of v 
//and even vertice in subtree of v

int subtree_sum[N];
int even[N];

void dfs(int vertex,int par=0){
    // Take action on vertex after entering
    // the vertex

    subtree_sum[vertex]+=vertex;
    if(vertex%2==0) even[vertex]++;
    for(int child:g[vertex]){
        // Take action on child before
        // entering the child node
        
        if(child==par) continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
        even[vertex]+=even[child];

        // Take action on child after
        // exiting the child node
    }
    // Take action on vertex before
    // exiting the vertex
}
int main() {
    int m;cin>>m;
    for(int i=0;i<m-1;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    dfs(1); 
    for(int i=1;i<=m;i++) cout<<subtree_sum[i]<<" "<<even[i]<<endl;
}