#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back


void dfs(int i,int j,vector<vector<int>>& image,int colour,int initialcolor){
    int n=image.size();
    int m=image[0].size();
    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(image[i][j]!=initialcolor) return;

    image[i][j]=colour;

    dfs(i+1,j,image,colour,initialcolor);    //FLOOD FILL ALGO
    dfs(i,j+1,image,colour,initialcolor);
    dfs(i-1,j,image,colour,initialcolor);
    dfs(i,j-1,image,colour,initialcolor);

    
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialcolour=image[sr][sc];
        if(initialcolour!=color)
            dfs(sr,sc,image,color,initialcolour);
        return image;
}
int main() {
    int t;cin>>t;
    
}
