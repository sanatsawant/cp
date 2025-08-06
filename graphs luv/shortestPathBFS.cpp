#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back

const int N=100;
vector<pair<int,int>> movements={
    {2,1},{2,-1},
    {-2,1},{-2,-1},
    {1,2},{1,-2},
    {-1,2},{-1,-2},
};
int level[N][N];
int vis[N][N];
void reset(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            vis[i][j]=0;
            level[i][j]=0;
        }
    }
}
int x_coord(char ch){
    return ch-'a';
}
int y_coord(char ch){
    return ch-'1';
}
bool isvalid(int x,int y){
    return (x>=0 && y>=0 && x<8 && y<8);
}
void bfs(int startx,int starty,int destx,int desty){
    queue<pair<int,int>> q;
    q.push({startx,starty});
    while(!q.empty()){
        auto v=q.front();
  
        vis[v.first][v.second]=1;
        q.pop();
        for(auto mov:movements){
            int posx=v.first+mov.first;
            int posy=v.second+mov.second;
            if(!isvalid(posx,posy) || vis[posx][posy]) continue;
            q.push({posx,posy});
            level[posx][posy]=level[v.first][v.second]+1;
        }
    }

}
void sanat(){
    string s,t;cin>>s>>t;
    int x=x_coord(s[0]);
    int y=y_coord(s[1]);
    int destx=x_coord(t[0]);
    int desty=y_coord(t[1]);
    //cout<<destx<<" "<<desty<<endl;
    bfs(x,y,destx,desty);
    cout<<level[destx][desty]<<endl;
    reset();

    
}

int main() {
    int t;cin>>t;
    while(t--){
        sanat();
    }
}
