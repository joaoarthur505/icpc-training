#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i=s;i<e;i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

// #ifdef DEBUG
// #define trace (u)
// #define _
// #else#define trace (u)
// #define _ ios::sync_with_stdio
// #endif

// #define debug(u) (trace)

const ll range = 1e5+1;

vector<vll> g(range);
vector<bool> vis1(range);
vector<bool> vis2(range);

void dfs1(ll v){
    vis1[v]=true;
    for(auto u:g[v]){
        if(!vis1[u]){
            vis1[u]=true;
            dfs1(u);
        }
    }
    return;
}

void dfs2(ll v){
    vis2[v]=true;
    for(auto u:g[v]){
        if(!vis2[u]){
            vis2[u]=true;
            dfs2(u);
        }
    }
    return;
}

int main(){
    ll n,m; cin >> n >> m;

    forn(i,0,m){
        ll x,y; cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
    }

    ll a,b; cin >> a >> b;
    a--;b--;

    dfs1(a);
    dfs2(b);

    bool encontro = false;
    ll estacao=-1;

    forn(i,0,n){
        if(vis1[i] && vis2[i]){encontro=true; estacao=i+1;}
    }

    if(encontro){cout << "yes" << ln; cout << estacao << ln;}
    else cout << "no" << ln;

    return 0;
}