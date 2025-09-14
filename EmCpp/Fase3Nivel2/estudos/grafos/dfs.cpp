#include<bits/stdc++.h>
using namespace std ; 
#define int long long 
#define ll long long
#define pb push_back
#define ff first 
#define ss second 
#define pii pair<ll,ll> 

const int maxn = 1e5 + 5 ; 

int ct ; 
int comp[maxn], vis[maxn] ; 

void dfs(int v, int p){

    vis[v] = 1 ; comp[v] = ct ; 

    for(auto a : grafo[v]){
        if(a == p || vis[a]) continue ; 
        dfs(a, v) ;
    }

}

int32_t main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 


    for(int i = 1 ; i <= n ; i++){
        if(vis[i]) continue ; 
        ct++ ; 
        dfs(i, i) ; 
    }
}
