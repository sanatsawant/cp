#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back
#define M 1000000007
const int N=1000;

ll d[N][N];
void solve(){
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i!=j) d[i][j]=1e18;
            else d[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w;
        d[u][v]=min(d[u][v],w);
        d[v][u]=min(d[v][u],w);

    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }

    }
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        cout<<(d[a][b]==1e18?-1:d[a][b])<<'\n';

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }
}
