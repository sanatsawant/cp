#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back
#define M 1000000007

================================================================================================

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// Oset st
// st.order_of_key(k)   → number of elements strictly less than k
// st.find_by_order(k)  → iterator to k-th smallest element (0-indexed)


==================================================================================================

// F: Greeting ---> Codeforces
const int N=1e5+10;
int t;
void solve(){
    
    int n;cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(all(v));
    ll ans=0;
    Oset st;
    for(auto x:v){
        ans+=st.size()-st.order_of_key(x.second);
        st.insert(x.second);
    }
    cout<<ans<<'\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        solve();
    }
}
