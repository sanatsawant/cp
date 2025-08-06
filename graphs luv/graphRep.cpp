#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back

const int N=1e3+10;
int graph1[N][N];
vector<pair<int,int>> graph2[N];  //2d vector //note --> []

int main(){
    int n,m;cin>>n>>m;  //m=edges
    for(int i=0;i<m;i++){
        int v1,v2,wt;cin>>v1>>v2>>wt;
        graph1[v1][v2]=wt;
        graph1[v2][v1]=wt;

        graph2[v1].pb({v2,wt});
        graph2[v2].pb({v1,wt});
        
    }
    
}
